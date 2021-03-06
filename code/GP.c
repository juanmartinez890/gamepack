#include <msp430.h>
#include <stdint.h>
#include "GP.h"

uint8_t gp_cur_spr = 0;    // current sprite, incremented by xsprite/xhide

uint16_t lfsr = 0xACE1;     // LFSR random number

uint8_t nes_data_1 = 0;
uint8_t nes_data_2 = 0;

void GP_begin(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;

    // put FPGA_CS pin in high Z state immediately
    // it's used for FPGA init
    P_FPGA_CS_DIR &= ~FPGA_CS_PIN;

    // let the fpga initialize
    uint16_t i = 0xFF;
    while (--i) { delay(0xFF); }

    // we can now drive FPGA_CS
    P_FPGA_CS_DIR |= FPGA_CS_PIN;

    // set it high initially (unselected)
    P1DIR |= FPGA_CS_PIN;


    // configure SPI
    P1DIR |= BIT7 | BIT5;           // UCB0CLK | UCB0SIMO
    P1DIR &= ~BIT6;                 // UCB0SOMI

    P1SEL |= BIT5 | BIT6 | BIT7;    // select SPI mode
    P1SEL2 |= BIT5 | BIT6 | BIT7;   // select SPI mode

    UCB0CTL1 = UCSWRST;             // reset the USCI to configure SPI
    UCB0CTL0 |= UCMST;              // master mode
    UCB0CTL0 |= UCMSB;              // MSB first
    UCB0CTL0 |= UCSYNC;             // syncronous
    UCB0CTL0 |= UCCKPH;             // mode 0
    UCB0CTL1 |= UCSSEL_2;           // SMCLK
    UCB0BR0 = 4;                    // divide clock by 4 (to get a 4MHz clock)
    UCB0BR1 = 0;
    UCB0CTL1 &= ~UCSWRST;           // clear UCSWRST

    // configure UART
    P1SEL |= (BIT1 | BIT2);
    P1SEL2 |= (BIT1 | BIT2);
    P1DIR |= BIT2;
    P1DIR &= ~BIT1;

    UCA0CTL1 |= UCSSEL_2;

    UCA0BR0 = 0xa0;                 // 100K baud
    UCA0BR1 = 0x00;
    UCA0MCTL = 0x00;

    UCA0CTL1 &= ~UCSWRST;


    // setup NES controller pins
    P_NES_DIR |= (NES_LATCH_PIN | NES_CLK_PIN);
    P_NES_DIR &= ~(NES_DATA_1_PIN | NES_DATA_2_PIN);

    GP_wr(J1_RESET, 1);           // HALT coprocessor
    __wstart(RAM_SPR);            // Hide all sprites
    for (i = 0; i < 512; i++)
        GP_xhide();
    __end();
    GP_fill(RAM_PIC, 0, 1024 * 10);  // Zero all character RAM
    GP_fill(RAM_SPRPAL, 0, 2048);    // Sprite palletes black
    GP_fill(RAM_SPRIMG, 0, 64 * 256);   // Clear all sprite data
    GP_fill(VOICES, 0, 256);         // Silence
    GP_fill(PALETTE16A, 0, 128);     // Black 16-, 4-palletes and COMM

    GP_wr16(SCROLL_X, 0);
    GP_wr16(SCROLL_Y, 0);
    GP_wr(JK_MODE, 0);
    GP_wr(SPR_DISABLE, 0);
    GP_wr(SPR_PAGE, 0);
    GP_wr(IOMODE, 0);
    GP_wr16(BG_COLOR, 0);
    GP_wr16(SAMPLE_L, 0);
    GP_wr16(SAMPLE_R, 0);
    GP_wr16(SCREENSHOT_Y, 0);
    GP_wr(MODULATOR, 64);

    // ensure the fpga has booted up
    GP_waitvblank();

    uint16_t j;
    for (i = 0; i < 0x50; i++)
        for (j = 0; j < 0xFF; j++)
            delay(0xFF);

}


void GP_sprite(uint8_t spr, uint16_t x, uint16_t y, uint8_t image, uint8_t palette, uint8_t rot, uint8_t jk)
{
    __wstart(RAM_SPR + (spr << 2));
    spi_transfer(LOW_BYTE(x));
    spi_transfer((palette << 4) | (rot << 1) | (HIGH_BYTE(x) & 1));
    spi_transfer(LOW_BYTE(y));
    spi_transfer((jk << 7) | (image << 1) | (HIGH_BYTE(y) & 1));
    __end();
}

void GP_xsprite(int16_t ox, int16_t oy, int8_t x, int8_t y, uint8_t image, uint8_t palette, uint8_t rot, uint8_t jk)
{
    if (rot & 2)
        x = -16-x;
    if (rot & 4)
        y = -16-y;
    if (rot & 1) {
        int s;
        s = x; x = y; y = s;
    }
    ox += x;
    oy += y;
    spi_transfer(LOW_BYTE(ox));
    spi_transfer((palette << 4) | (rot << 1) | (HIGH_BYTE(ox) & 1));
    spi_transfer(LOW_BYTE(oy));
    spi_transfer((jk << 7) | (image << 1) | (HIGH_BYTE(oy) & 1));
    gp_cur_spr++;
}


#include "font8x8.h"
static uint8_t stretch[16] = {
    0x00, 0x03, 0x0c, 0x0f,
    0x30, 0x33, 0x3c, 0x3f,
    0xc0, 0xc3, 0xcc, 0xcf,
    0xf0, 0xf3, 0xfc, 0xff
};

void GP_ascii(void)
{
    uint16_t i;

    for (i = 0; i < 768; i++) {
        uint8_t b = font8x8[i];

        uint8_t h = stretch[b >> 4];
        uint8_t l = stretch[b & 0xf];
        GP_wr(0x1000 + (16 * ' ') + (2 * i), h);
        GP_wr(0x1000 + (16 * ' ') + (2 * i) + 1, l);
    }
    for (i = 0x20; i < 0x80; i++) {
        GP_setpal(4 * i + 0, TRANSPARENT);
        GP_setpal(4 * i + 3, RGB(255,255,255));
    }
    GP_fill(RAM_PIC, ' ', 4096);

}

void GP_putstr(uint16_t x, uint16_t y, const char *s)
{
    __wstart((y << 6) + x);
    while (*s)
        spi_transfer(*s++);
    __end();
}

void GP_putnum(uint16_t x, uint16_t y, uint8_t s)
{
    __wstart((y << 6) + x);
    spi_transfer('0'+s);
    __end();
}

void GP_setpal(uint16_t pal, uint16_t rgb)
{
    GP_wr16(RAM_PAL + (pal << 1), rgb);
}


void GP_fill(uint16_t addr, uint8_t v, uint16_t count)
{
    __wstart(addr);
    while (count--)
        spi_transfer(v);
    __end();
}

void GP_copy(uint16_t addr, const uint8_t *src, uint16_t count)
{
    __wstart(addr);
    while (count--)
    {
        spi_transfer(*(const uint8_t*)src);
        src++;
    }
    __end();
}

void GP_xhide(void)
{
    spi_transfer(LOW_BYTE(400));
    spi_transfer(HIGH_BYTE(400));
    spi_transfer(LOW_BYTE(400));
    spi_transfer(HIGH_BYTE(400));
    gp_cur_spr++;
}

void GP_waitvblank(void)
{
    while (GP_rd(VBLANK) == 1);
    while (GP_rd(VBLANK) == 0);
}

void GP_screenshot(uint16_t frame)
{
  uint16_t yy, xx;
  uint8_t undone[38];  // 300-long bitmap of lines pending

  // initialize to 300 ones
  uint8_t i = 0;
  for (i = 0; i < 38; i++)
      undone[i] = 0xFF;

  undone[37] = 0xf;
  uint16_t nundone = 300;

  uart_send(0xa5);   // sync byte
  uart_send(LOW_BYTE(frame));
  uart_send(HIGH_BYTE(frame));

  while (nundone) {
    // find a pending line a short distance ahead of the raster
    uint16_t hwline = GP_rd16(SCREENSHOT_Y) & 0x1ff;
    for (yy = (hwline + 7) % 300; ((undone[yy>>3] >> (yy&7)) & 1) == 0; yy = (yy + 1) % 300);
    GP_wr16(SCREENSHOT_Y, 0x8000 | yy);   // ask for it

    // housekeeping while waiting: mark line done and send yy
    undone[yy>>3] ^= (1 << (yy&7));
    nundone--;
    uart_send(LOW_BYTE(yy));
    uart_send(HIGH_BYTE(yy));
    while ((GP_rd(SCREENSHOT_Y + 1) & 0x80) == 0);

    // Now send the line, compressing zero pixels
    uint16_t zeroes = 0;
    for (xx = 0; xx < 800; xx += 2) {
      uint16_t v = GP_rd16(SCREENSHOT + xx);
      if (v == 0) {
        zeroes++;
      } else {
        if (zeroes) {
          uart_send(LOW_BYTE(zeroes));
          uart_send(0x80 | HIGH_BYTE(zeroes));
          zeroes = 0;
        }
        uart_send(LOW_BYTE(v));
        uart_send(HIGH_BYTE(v));
      }
    }
    if (zeroes) {
      uart_send(LOW_BYTE(zeroes));
      uart_send(0x80 | HIGH_BYTE(zeroes));
    }
  }
  GP_wr16(SCREENSHOT_Y, 0);   // restore screen to normal
}

void GP_wr(uint16_t addr, uint8_t v)
{
    __wstart(addr);
    spi_transfer(v);
    __end();
}

void GP_wr16(uint16_t addr, uint16_t v)
{
  __wstart(addr);
  spi_transfer(LOW_BYTE(v));
  spi_transfer(HIGH_BYTE(v));
  __end();
}

uint8_t GP_rd(uint16_t addr)
{
    __start(addr);
    uint8_t r = spi_transfer(0x00);
    __end();
    return r;
}

uint16_t GP_rd16(uint16_t addr)
{
    uint16_t r;

    __start(addr);
    r = spi_transfer(0);
    r |= (spi_transfer(0) << 8);
    __end();

    return r;
}

void __wstart(uint16_t addr)
{
    __start(0x8000 | addr);
}

void __wstartspr(uint8_t sprnum)
{
    __start((0x8000 | RAM_SPR) + (sprnum << 2));
    gp_cur_spr = 0;
}

void __start(uint16_t addr)
{
    P_FPGA_CS_OUT &= ~FPGA_CS_PIN;
    spi_transfer(HIGH_BYTE(addr));
    spi_transfer(LOW_BYTE(addr));
}

void __end(void)
{
    P_FPGA_CS_OUT |= FPGA_CS_PIN;
}

uint8_t spi_transfer(uint8_t byte)
{
    UCB0TXBUF = byte;
    while(UCB0STAT & UCBUSY);     // wait for tx to finish
    return UCB0RXBUF;
}

void uart_send(uint8_t byte)
{
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = byte;
}


void delay(uint16_t ms)
{
    //TODO implement ms delay. Use a timer I suppose. I'll do this tomorrow, I need to go to sleep
    volatile uint16_t i = ms;
    while (i) { i--; };
}

void GP_nes_read(void)
{
    nes_data_1 = 0;
    nes_data_2 = 0;

    P_NES_OUT |= NES_LATCH_PIN;
    P_NES_OUT &= ~NES_LATCH_PIN;
    delay(5);

    if ((~P_NES_IN) & NES_DATA_1_PIN) nes_data_1 = 1;
    delay(5);
    if ((~P_NES_IN) & NES_DATA_2_PIN) nes_data_2 = 1;
    delay(5);

    uint8_t i = 8;
    while (--i)
    {
        P_NES_OUT |= NES_CLK_PIN;
        P_NES_OUT &= ~NES_CLK_PIN;

        nes_data_1 <<= 1;
        nes_data_2 <<= 1;

        if ((~P_NES_IN) & NES_DATA_1_PIN){ nes_data_1 |= 1;}
        delay(5);
        if ((~P_NES_IN) & NES_DATA_2_PIN){ nes_data_2 |= 1;}
        delay(5);
    }
}

uint16_t random(uint16_t min, uint16_t max)
{
    if (min > max) return 0;

    if (min == max) return min;

    uint16_t spread = max - min;

    uint8_t i = 1;
    uint16_t mask = 0x0000;

    // increase mask size until it is just bigger than our max value
    for (i = 1; i<16; i++)
    {
        mask = ~(0xFFFF << i);

        // if our masked value is bigger than max value
        if (mask > spread) break;
    }

    uint16_t result = 0;
    do
    {
        // get new random number
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);

        // mask the number to get it close to our spread
        result = lfsr & mask;

    } while (result > spread);

    result += min;

    return result;
}
