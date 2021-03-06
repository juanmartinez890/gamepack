#define SPRITE_FRAMES 12
static void draw_sprite(int x, int y, uint8_t anim, uint8_t rot, uint8_t jk) {
  switch (anim) {
  case 0:
    GP_xsprite(x, y, -8, -8, 0, 4, rot, jk);
    break;
  case 1:
    GP_xsprite(x, y, -8, -8, 0, 6, rot, jk);
    break;
  case 2:
    GP_xsprite(x, y, -8, -8, 1, 4, rot, jk);
    break;
  case 3:
    GP_xsprite(x, y, -8, -8, 1, 6, rot, jk);
    break;
  case 4:
    GP_xsprite(x, y, -8, -8, 2, 4, rot, jk);
    break;
  case 5:
    GP_xsprite(x, y, -8, -8, 2, 6, rot, jk);
    break;
  case 6:
    GP_xsprite(x, y, -8, -8, 3, 4, rot, jk);
    break;
  case 7:
    GP_xsprite(x, y, -8, -8, 3, 6, rot, jk);
    break;
  case 8:
    GP_xsprite(x, y, -8, -8, 4, 4, rot, jk);
    break;
  case 9:
    GP_xsprite(x, y, -8, -8, 4, 6, rot, jk);
    break;
  case 10:
    GP_xsprite(x, y, -8, -8, 5, 4, rot, jk);
    break;
  case 11:
    GP_xsprite(x, y, -8, -8, 5, 6, rot, jk);
    break;
  }
}

const uint8_t sprite_img[] = {

0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x11,  0x22,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x22,  0x00,  0x22,  0x00,  0x22,  0x22,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x22,  0x00,  0x22,  0x00,  0x22,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x31,  0x33,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x33,  0x33,  0x33,  0x33,  0x33,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x12,  0x30,  0x33,  0x31,  0x11,  0x11,  0x13,  0x33,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x12,  0x31,  0x31,  0x31,  0x31,  0x11,  0x13,  0x13,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x20,  0x20,  0x31,  0x31,  0x31,  0x31,  0x23,  0x13,  0x13,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x22,  0x20,  0x30,  0x33,  0x33,  0x23,  0x23,  0x13,  0x33,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x02,  0x31,  0x33,  0x33,  0x23,  0x21,  0x33,  0x33,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x02,  0x01,  0x11,  0x13,  0x33,  0x11,  0x11,  0x01,  0x01,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x02,  0x01,  0x23,  0x23,  0x00,  0x11,  0x11,  0x01,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x20,  0x20,  0x00,  0x20,  0x20,  0x02,  0x02,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x20,  0x22,  0x02,  0x00,  0x00,  0x00,  0x00, 

0x00,  0x00,  0x00,  0x20,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x31,  0x01,  0x11,  0x11,  0x11,  0x11,  0x10,  0x13,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x01,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x10,  0x10,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x10,  0x12,  0x10,  0x22,  0x22,  0x01,  0x21,  0x01,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x02,  0x10,  0x12,  0x10,  0x12,  0x21,  0x01,  0x21,  0x01,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x01,  0x01,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x10,  0x10,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x01,  0x31,  0x31,  0x11,  0x11,  0x13,  0x13,  0x10,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x30,  0x10,  0x13,  0x33,  0x33,  0x31,  0x01,  0x03,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x10,  0x13,  0x13,  0x33,  0x33,  0x31,  0x31,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x12,  0x12,  0x13,  0x33,  0x33,  0x33,  0x33,  0x31,  0x21,  0x21,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x22,  0x12,  0x31,  0x33,  0x33,  0x33,  0x33,  0x13,  0x21,  0x22,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x30,  0x31,  0x33,  0x33,  0x33,  0x33,  0x13,  0x03,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x10,  0x10,  0x30,  0x30,  0x30,  0x11,  0x11,  0x03,  0x03,  0x03,  0x01,  0x01,  0x00,  0x00, 
0x00,  0x20,  0x20,  0x10,  0x10,  0x00,  0x10,  0x11,  0x11,  0x01,  0x00,  0x01,  0x01,  0x02,  0x02,  0x00, 
0x00,  0x20,  0x00,  0x00,  0x00,  0x00,  0x20,  0x20,  0x02,  0x02,  0x00,  0x00,  0x00,  0x00,  0x02,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x22,  0x22,  0x02,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 

0x00,  0x00,  0x00,  0x22,  0x11,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x22,  0x22,  0x00,  0x22,  0x00,  0x22,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x22,  0x00,  0x22,  0x00,  0x22,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x13,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x33,  0x33,  0x33,  0x33,  0x33,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x33,  0x31,  0x11,  0x11,  0x13,  0x33,  0x03,  0x21,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x31,  0x31,  0x11,  0x13,  0x13,  0x13,  0x13,  0x21,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x31,  0x31,  0x32,  0x13,  0x13,  0x13,  0x13,  0x02,  0x02,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x33,  0x31,  0x32,  0x32,  0x33,  0x33,  0x03,  0x02,  0x22,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x33,  0x33,  0x12,  0x32,  0x33,  0x33,  0x13,  0x20,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x10,  0x11,  0x11,  0x33,  0x31,  0x11,  0x10,  0x20,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x10,  0x11,  0x11,  0x00,  0x32,  0x32,  0x10,  0x20,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x20,  0x20,  0x02,  0x02,  0x00,  0x02,  0x02,  0x02,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x20,  0x22,  0x02,  0x02,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 

0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x22,  0x00,  0x22,  0x22,  0x00,  0x22,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x22,  0x00,  0x22,  0x22,  0x00,  0x22,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x33,  0x33,  0x33,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x13,  0x33,  0x33,  0x33,  0x33,  0x11,  0x11,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x11,  0x11,  0x33,  0x33,  0x33,  0x33,  0x33,  0x33,  0x11,  0x12,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x21,  0x11,  0x33,  0x33,  0x33,  0x33,  0x33,  0x33,  0x10,  0x20,  0x20,  0x00,  0x00, 
0x00,  0x00,  0x22,  0x22,  0x00,  0x33,  0x33,  0x33,  0x33,  0x33,  0x33,  0x00,  0x20,  0x20,  0x00,  0x00, 
0x00,  0x00,  0x02,  0x02,  0x00,  0x33,  0x33,  0x33,  0x33,  0x31,  0x31,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x33,  0x33,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x12,  0x12,  0x00,  0x00,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x22,  0x22,  0x00,  0x00,  0x22,  0x22,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x20,  0x00,  0x00,  0x22,  0x22,  0x00,  0x00,  0x00,  0x00,  0x00, 

0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x31,  0x31,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x12,  0x10,  0x12,  0x12,  0x30,  0x12,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x12,  0x10,  0x12,  0x12,  0x10,  0x12,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x33,  0x33,  0x33,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x02,  0x02,  0x11,  0x31,  0x33,  0x33,  0x33,  0x33,  0x33,  0x11,  0x20,  0x20,  0x00,  0x00, 
0x00,  0x00,  0x02,  0x12,  0x11,  0x33,  0x33,  0x23,  0x23,  0x33,  0x33,  0x11,  0x21,  0x20,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x10,  0x33,  0x33,  0x23,  0x23,  0x33,  0x33,  0x01,  0x01,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x00,  0x13,  0x13,  0x13,  0x13,  0x13,  0x13,  0x00,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x20,  0x20,  0x00,  0x31,  0x31,  0x33,  0x33,  0x33,  0x33,  0x00,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x11,  0x11,  0x33,  0x33,  0x11,  0x11,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x21,  0x21,  0x00,  0x00,  0x12,  0x12,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x22,  0x22,  0x00,  0x00,  0x22,  0x22,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x02,  0x02,  0x00,  0x00,  0x20,  0x20,  0x00,  0x00,  0x00,  0x00,  0x00, 

0x00,  0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x11,  0x11,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x31,  0x33,  0x13,  0x11,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x11,  0x11,  0x31,  0x13,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x10,  0x11,  0x11,  0x11,  0x11,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x00,  0x30,  0x33,  0x33,  0x33,  0x03,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x20,  0x20,  0x10,  0x31,  0x33,  0x33,  0x33,  0x33,  0x33,  0x13,  0x01,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x20,  0x20,  0x11,  0x31,  0x33,  0x33,  0x33,  0x33,  0x33,  0x13,  0x11,  0x01,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x02,  0x02,  0x31,  0x33,  0x23,  0x22,  0x32,  0x33,  0x13,  0x11,  0x02,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x02,  0x02,  0x10,  0x11,  0x11,  0x11,  0x11,  0x11,  0x01,  0x20,  0x22,  0x02,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x30,  0x33,  0x33,  0x33,  0x33,  0x33,  0x03,  0x20,  0x20,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x10,  0x11,  0x31,  0x33,  0x13,  0x11,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x10,  0x11,  0x01,  0x00,  0x20,  0x21,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x20,  0x22,  0x02,  0x00,  0x20,  0x22,  0x02,  0x00,  0x00,  0x00,  0x00,  0x00, 
0x00,  0x00,  0x00,  0x00,  0x20,  0x22,  0x02,  0x00,  0x00,  0x02,  0x02,  0x00,  0x00,  0x00,  0x00,  0x00, 
};
const uint8_t sprite_pal[] = {

0x00,  0x80,  0xff,  0x7f,  0xeb,  0x7d,  0xff,  0x1e, 
};
