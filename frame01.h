/* 

  GameBoy ToolKit v0.013a

  Filename : frame01.h
  Source   : frame_07_delay-0.7s.jpg

  Number of Tiles   : 37
  TileMap Size      : 7x7

*/ 

const unsigned char frame01_tiledata[] = {
0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x0F,0x00,0x03,0x00,0x03,0x08,0x0B,0x00,
0x29,0x00,0x47,0x38,0x86,0xF8,0x05,0xFA,0x21,0xFE,0x29,0xFE,0x29,0xFE,0x2E,0xFC,
0x14,0xAA,0xF8,0x00,0x26,0xF8,0x20,0xFF,0x28,0xFF,0x2A,0xFF,0x2A,0xFF,0x2A,0xFF,
0x80,0x00,0xC0,0x20,0xB8,0x00,0xEC,0x02,0x1F,0xE0,0x17,0xE8,0x15,0xEA,0x00,0xFF,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0xFF,0x00,0x5F,0xA0,0x55,0xAA,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xAE,0x00,0xA3,0x00,
0x08,0x03,0x0C,0x03,0x1C,0x03,0x1C,0x03,0x1C,0x03,0x30,0x0F,0x32,0x0F,0x12,0x2F,
0x2E,0xFC,0x2C,0xFE,0x2A,0xFF,0x2A,0xFF,0x22,0xFF,0x82,0xFF,0x92,0xEF,0xB0,0xCF,
0x2A,0xFF,0x0A,0xFF,0x0A,0xFF,0xAA,0xFF,0x2E,0xFF,0x02,0xFF,0x84,0xFB,0x05,0xFA,
0x00,0xFF,0x80,0xFF,0xAA,0xFF,0xAA,0xFF,0xAA,0xFF,0xEA,0xFF,0xFE,0xFF,0x2F,0xFF,
0x55,0xAA,0x05,0xFA,0x01,0xFE,0x01,0xFE,0x80,0xFF,0xA0,0xFF,0xA8,0xFF,0xAA,0xFF,
0x68,0x80,0x78,0x80,0x78,0x80,0x78,0x80,0x7E,0x80,0x56,0xA8,0x16,0xE8,0x16,0xE8,
0x32,0x0F,0x22,0x1F,0x00,0x3F,0x02,0x3F,0x30,0x0F,0x3C,0x03,0x04,0x0B,0x08,0x03,
0xB2,0xCF,0x80,0xCF,0xA8,0xC7,0x94,0xEB,0xA8,0xFF,0xAA,0xFF,0xA3,0xFE,0xA0,0xFF,
0x05,0xFA,0xA1,0xFE,0x80,0xFF,0x20,0xFF,0x08,0xFF,0xA0,0xFF,0x6A,0xFF,0xCA,0x3F,
0x53,0xAF,0x54,0xAB,0x57,0xA8,0x15,0xEA,0x15,0xEA,0x01,0xFE,0x00,0xFF,0xA0,0xFF,
0xEA,0xFF,0xEA,0xFF,0x2A,0xFF,0xD0,0x2F,0x5F,0xA0,0x5E,0xA0,0x1F,0xE0,0x17,0xE8,
0x84,0xFA,0x86,0xF8,0xA6,0xF8,0x18,0xE0,0x60,0x80,0xA0,0x00,0xA0,0x00,0xA0,0x00,
0x02,0x01,0x02,0x01,0x03,0x00,0x09,0x00,0x26,0x18,0x03,0x3E,0x42,0x3F,0xAA,0x1F,
0xA0,0xFF,0x21,0xFE,0x01,0xFE,0x01,0xFE,0x80,0x7F,0xC0,0x3F,0x50,0xAF,0x9C,0xE3,
0xFE,0x8F,0x3E,0xE3,0x07,0xF8,0x43,0xBE,0x52,0xAF,0x50,0xAF,0x14,0xEB,0x05,0xFA,
0xA8,0xFF,0xA8,0xFF,0xEA,0xFF,0x6A,0x3F,0x2E,0x9F,0x8E,0xFF,0x2F,0xFF,0x0A,0xFF,
0x05,0xFA,0x05,0xFA,0x81,0xFE,0x01,0xFE,0xA0,0xFF,0xA8,0xFF,0xA8,0xFF,0xA8,0xFF,
0xE0,0x00,0xE8,0x00,0x78,0x80,0x78,0x80,0x58,0xA0,0x58,0xA0,0x19,0xE0,0x59,0xA0,
0xAA,0x1F,0x22,0x9F,0x92,0x0F,0x12,0x0F,0x08,0x07,0x00,0x03,0x0B,0x00,0x08,0x00,
0xA7,0xF8,0xAB,0xFC,0xA9,0xFE,0xAA,0xFF,0x2A,0xFF,0x2B,0xFF,0x02,0xFF,0x02,0xFF,
0x05,0xFA,0x41,0xBE,0x51,0xAE,0x50,0xAF,0xD0,0xAF,0xA4,0xFB,0xE4,0xFB,0xB9,0xFE,
0x02,0xFF,0x54,0xAB,0x5D,0xA2,0x5F,0xA0,0x17,0xE8,0x05,0xFA,0x05,0xFA,0x01,0xFE,
0xA8,0xFF,0xA0,0xFF,0x50,0xAF,0xFF,0x00,0xFA,0x00,0xF8,0x00,0x58,0xA0,0x5E,0xA0,
0x5B,0xA0,0x5A,0xA0,0x5E,0xA0,0xEC,0x00,0x88,0x00,0x08,0x00,0x00,0x00,0x20,0x00,
0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x3F,0x00,0x3F,0xB0,0x0F,0x00,0x0F,0x2C,0x03,0x2C,0x03,0x0D,0x02,0x0F,0x00,
0xA8,0xFF,0x8A,0xFF,0x8A,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
0x00,0xFF,0x01,0xFE,0x01,0xFE,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
0x5A,0xA0,0x5E,0xA0,0x56,0xA8,0x05,0xF8,0x5A,0xA0,0x4E,0xA0,0x7C,0x80,0x78,0x80,
0x00,0x20,0xC0,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

const unsigned char frame01_tilemap[] = {
0x00,0x01,0x02,0x03,0x04,0x05,
0x06,0x07,0x08,0x09,0x0A,0x0B,
0x0C,0x0D,0x0E,0x0F,0x10,0x11,
0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x1A,0x1B,0x1C,0x1D,
0x1E,0x1F,0x20,0x21,0x22,0x23};
