/*   Amsat P3 FEC Encoder/decoder system.   Look-up tables
     created by Phil Karn KA9Q and James Miller G3RUH
     Last modified 2003 Jun 20  */


/* 8-bit parity table */
unsigned char Partab[] = {
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
};

/* Tables for Viterbi r=1/2 k=7 decoder to CCSDS standard */
/* ------------------------------------------------------ */

/* Metric table, [sent sym][rx symbol] */
/* This metric table is for an 8-bit ADC, which is total overkill!
   Simplify later.  128-i and i-128 would probably do!  jrm */


int mettab[2][256]= {
    {
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   19,   19,   19,   19,   19,   19,   19,   19,   19,
  19,   19,   18,   18,   18,   18,   18,   18,   17,   17,   17,   16,   16,   16,   15,   15,
  14,   14,   13,   13,   12,   11,   10,   10,    9,    8,    7,    6,    5,    3,    2,    1,
  -1,   -2,   -4,   -5,   -7,   -9,  -11,  -13,  -15,  -17,  -19,  -21,  -23,  -25,  -28,  -30,
 -32,  -35,  -37,  -40,  -42,  -45,  -47,  -50,  -52,  -55,  -58,  -60,  -63,  -66,  -68,  -71,
 -74,  -77,  -79,  -82,  -85,  -88,  -90,  -93,  -96,  -99, -102, -104, -107, -110, -113, -116,
-119, -121, -124, -127, -130, -133, -136, -138, -141, -144, -147, -150, -153, -155, -158, -161,
-164, -167, -170, -172, -175, -178, -181, -184, -187, -190, -192, -195, -198, -201, -204, -207,
-210, -212, -215, -218, -221, -224, -227, -229, -232, -235, -238, -241, -244, -247, -249, -252,
-255, -258, -261, -264, -267, -269, -272, -275, -278, -281, -284, -286, -289, -292, -295, -298,
-301, -304, -306, -309, -312, -315, -318, -320, -324, -326, -329, -332, -335, -337, -341, -372 },
    {

-372, -341, -338, -335, -332, -329, -326, -324, -321, -318, -315, -312, -309, -306, -304, -301,
-298, -295, -292, -289, -286, -284, -281, -278, -275, -272, -269, -267, -264, -261, -258, -255,
-252, -249, -247, -244, -241, -238, -235, -232, -229, -227, -224, -221, -218, -215, -212, -210,
-207, -204, -201, -198, -195, -192, -190, -187, -184, -181, -178, -175, -172, -170, -167, -164,
-161, -158, -155, -153, -150, -147, -144, -141, -138, -136, -133, -130, -127, -124, -121, -119,
-116, -113, -110, -107, -104, -102,  -99,  -96,  -93,  -90,  -88,  -85,  -82,  -79,  -77,  -74,
 -71,  -68,  -66,  -63,  -60,  -58,  -55,  -52,  -50,  -47,  -45,  -42,  -40,  -37,  -35,  -32,
 -30,  -28,  -25,  -23,  -21,  -19,  -17,  -15,  -13,  -11,   -9,   -7,   -5,   -4,   -2,   -1,
   1,    2,    3,    5,    6,    7,    8,    9,   10,   10,   11,   12,   13,   13,   14,   14,
  15,   15,   16,   16,   16,   17,   17,   17,   18,   18,   18,   18,   18,   18,   19,   19,
  19,   19,   19,   19,   19,   19,   19,   19,   19,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
  20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,   20}
};


/* Table of symbol pair emitted for each state of the convolutional
 encoder's shift register */ 
int Syms[]={
  1, 2, 3, 0, 2, 1, 0, 3, 2, 1, 0, 3, 1, 2, 3, 0,
  1, 2, 3, 0, 2, 1, 0, 3, 2, 1, 0, 3, 1, 2, 3, 0,
  0, 3, 2, 1, 3, 0, 1, 2, 3, 0, 1, 2, 0, 3, 2, 1,
  0, 3, 2, 1, 3, 0, 1, 2, 3, 0, 1, 2, 0, 3, 2, 1,
  2, 1, 0, 3, 1, 2, 3, 0, 1, 2, 3, 0, 2, 1, 0, 3,
  2, 1, 0, 3, 1, 2, 3, 0, 1, 2, 3, 0, 2, 1, 0, 3,
  3, 0, 1, 2, 0, 3, 2, 1, 0, 3, 2, 1, 3, 0, 1, 2,
  3, 0, 1, 2, 0, 3, 2, 1, 0, 3, 2, 1, 3, 0, 1, 2, 
};


/* Scramble byte table */

unsigned char Scrambler[]=
  {
   0xff, 0x48, 0x0e, 0xc0, 0x9a, 0x0d, 0x70, 0xbc, 0x8e, 0x2c, 0x93, 0xad, 0xa7, 0xb7, 0x46, 0xce,
   0x5a, 0x97, 0x7d, 0xcc, 0x32, 0xa2, 0xbf, 0x3e, 0x0a, 0x10, 0xf1, 0x88, 0x94, 0xcd, 0xea, 0xb1,
   0xfe, 0x90, 0x1d, 0x81, 0x34, 0x1a, 0xe1, 0x79, 0x1c, 0x59, 0x27, 0x5b, 0x4f, 0x6e, 0x8d, 0x9c,
   0xb5, 0x2e, 0xfb, 0x98, 0x65, 0x45, 0x7e, 0x7c, 0x14, 0x21, 0xe3, 0x11, 0x29, 0x9b, 0xd5, 0x63,
   0xfd, 0x20, 0x3b, 0x02, 0x68, 0x35, 0xc2, 0xf2, 0x38, 0xb2, 0x4e, 0xb6, 0x9e, 0xdd, 0x1b, 0x39,
   0x6a, 0x5d, 0xf7, 0x30, 0xca, 0x8a, 0xfc, 0xf8, 0x28, 0x43, 0xc6, 0x22, 0x53, 0x37, 0xaa, 0xc7,
   0xfa, 0x40, 0x76, 0x04, 0xd0, 0x6b, 0x85, 0xe4, 0x71, 0x64, 0x9d, 0x6d, 0x3d, 0xba, 0x36, 0x72,
   0xd4, 0xbb, 0xee, 0x61, 0x95, 0x15, 0xf9, 0xf0, 0x50, 0x87, 0x8c, 0x44, 0xa6, 0x6f, 0x55, 0x8f,
   0xf4, 0x80, 0xec, 0x09, 0xa0, 0xd7, 0x0b, 0xc8, 0xe2, 0xc9, 0x3a, 0xda, 0x7b, 0x74, 0x6c, 0xe5,
   0xa9, 0x77, 0xdc, 0xc3, 0x2a, 0x2b, 0xf3, 0xe0, 0xa1, 0x0f, 0x18, 0x89, 0x4c, 0xde, 0xab, 0x1f,
   0xe9, 0x01, 0xd8, 0x13, 0x41, 0xae, 0x17, 0x91, 0xc5, 0x92, 0x75, 0xb4, 0xf6, 0xe8, 0xd9, 0xcb,
   0x52, 0xef, 0xb9, 0x86, 0x54, 0x57, 0xe7, 0xc1, 0x42, 0x1e, 0x31, 0x12, 0x99, 0xbd, 0x56, 0x3f,
   0xd2, 0x03, 0xb0, 0x26, 0x83, 0x5c, 0x2f, 0x23, 0x8b, 0x24, 0xeb, 0x69, 0xed, 0xd1, 0xb3, 0x96,
   0xa5, 0xdf, 0x73, 0x0c, 0xa8, 0xaf, 0xcf, 0x82, 0x84, 0x3c, 0x62, 0x25, 0x33, 0x7a, 0xac, 0x7f,
   0xa4, 0x07, 0x60, 0x4d, 0x06, 0xb8, 0x5e, 0x47, 0x16, 0x49, 0xd6, 0xd3, 0xdb, 0xa3, 0x67, 0x2d,
   0x4b, 0xbe, 0xe6, 0x19, 0x51, 0x5f, 0x9f, 0x05, 0x08, 0x78, 0xc4, 0x4a, 0x66, 0xf5, 0x58, 0xff,
   0x48, 0x0e, 0xc0, 0x9a, 0x0d, 0x70, 0xbc, 0x8e, 0x2c, 0x93, 0xad, 0xa7, 0xb7, 0x46, 0xce, 0x5a,
   0x97, 0x7d, 0xcc, 0x32, 0xa2, 0xbf, 0x3e, 0x0a, 0x10, 0xf1, 0x88, 0x94, 0xcd, 0xea, 0xb1, 0xfe,
   0x90, 0x1d, 0x81, 0x34, 0x1a, 0xe1, 0x79, 0x1c, 0x59, 0x27, 0x5b, 0x4f, 0x6e, 0x8d, 0x9c, 0xb5,
   0x2e, 0xfb, 0x98, 0x65, 0x45, 0x7e, 0x7c, 0x14, 0x21, 0xe3, 0x11, 0x29, 0x9b, 0xd5, 0x63, 0xfd,
} ;



/* Tables for RS decoder */
/* Galois field log/antilog tables */
unsigned char ALPHA_TO[] =
  {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x87, 0x89, 0x95, 0xad, 0xdd, 0x3d, 0x7a, 0xf4,
    0x6f, 0xde, 0x3b, 0x76, 0xec, 0x5f, 0xbe, 0xfb, 0x71, 0xe2, 0x43, 0x86, 0x8b, 0x91, 0xa5, 0xcd,
    0x1d, 0x3a, 0x74, 0xe8, 0x57, 0xae, 0xdb, 0x31, 0x62, 0xc4, 0x0f, 0x1e, 0x3c, 0x78, 0xf0, 0x67,
    0xce, 0x1b, 0x36, 0x6c, 0xd8, 0x37, 0x6e, 0xdc, 0x3f, 0x7e, 0xfc, 0x7f, 0xfe, 0x7b, 0xf6, 0x6b,
    0xd6, 0x2b, 0x56, 0xac, 0xdf, 0x39, 0x72, 0xe4, 0x4f, 0x9e, 0xbb, 0xf1, 0x65, 0xca, 0x13, 0x26,
    0x4c, 0x98, 0xb7, 0xe9, 0x55, 0xaa, 0xd3, 0x21, 0x42, 0x84, 0x8f, 0x99, 0xb5, 0xed, 0x5d, 0xba,
    0xf3, 0x61, 0xc2, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe0,
    0x47, 0x8e, 0x9b, 0xb1, 0xe5, 0x4d, 0x9a, 0xb3, 0xe1, 0x45, 0x8a, 0x93, 0xa1, 0xc5, 0x0d, 0x1a,
    0x34, 0x68, 0xd0, 0x27, 0x4e, 0x9c, 0xbf, 0xf9, 0x75, 0xea, 0x53, 0xa6, 0xcb, 0x11, 0x22, 0x44,
    0x88, 0x97, 0xa9, 0xd5, 0x2d, 0x5a, 0xb4, 0xef, 0x59, 0xb2, 0xe3, 0x41, 0x82, 0x83, 0x81, 0x85,
    0x8d, 0x9d, 0xbd, 0xfd, 0x7d, 0xfa, 0x73, 0xe6, 0x4b, 0x96, 0xab, 0xd1, 0x25, 0x4a, 0x94, 0xaf,
    0xd9, 0x35, 0x6a, 0xd4, 0x2f, 0x5e, 0xbc, 0xff, 0x79, 0xf2, 0x63, 0xc6, 0x0b, 0x16, 0x2c, 0x58,
    0xb0, 0xe7, 0x49, 0x92, 0xa3, 0xc1, 0x05, 0x0a, 0x14, 0x28, 0x50, 0xa0, 0xc7, 0x09, 0x12, 0x24,
    0x48, 0x90, 0xa7, 0xc9, 0x15, 0x2a, 0x54, 0xa8, 0xd7, 0x29, 0x52, 0xa4, 0xcf, 0x19, 0x32, 0x64,
    0xc8, 0x17, 0x2e, 0x5c, 0xb8, 0xf7, 0x69, 0xd2, 0x23, 0x46, 0x8c, 0x9f, 0xb9, 0xf5, 0x6d, 0xda,
    0x33, 0x66, 0xcc, 0x1f, 0x3e, 0x7c, 0xf8, 0x77, 0xee, 0x5b, 0xb6, 0xeb, 0x51, 0xa2, 0xc3, 0x00,
  } ;

unsigned char INDEX_OF[]=
  {
   0xff, 0x00, 0x01, 0x63, 0x02, 0xc6, 0x64, 0x6a, 0x03, 0xcd, 0xc7, 0xbc, 0x65, 0x7e, 0x6b, 0x2a,
   0x04, 0x8d, 0xce, 0x4e, 0xc8, 0xd4, 0xbd, 0xe1, 0x66, 0xdd, 0x7f, 0x31, 0x6c, 0x20, 0x2b, 0xf3,
   0x05, 0x57, 0x8e, 0xe8, 0xcf, 0xac, 0x4f, 0x83, 0xc9, 0xd9, 0xd5, 0x41, 0xbe, 0x94, 0xe2, 0xb4,
   0x67, 0x27, 0xde, 0xf0, 0x80, 0xb1, 0x32, 0x35, 0x6d, 0x45, 0x21, 0x12, 0x2c, 0x0d, 0xf4, 0x38,
   0x06, 0x9b, 0x58, 0x1a, 0x8f, 0x79, 0xe9, 0x70, 0xd0, 0xc2, 0xad, 0xa8, 0x50, 0x75, 0x84, 0x48,
   0xca, 0xfc, 0xda, 0x8a, 0xd6, 0x54, 0x42, 0x24, 0xbf, 0x98, 0x95, 0xf9, 0xe3, 0x5e, 0xb5, 0x15,
   0x68, 0x61, 0x28, 0xba, 0xdf, 0x4c, 0xf1, 0x2f, 0x81, 0xe6, 0xb2, 0x3f, 0x33, 0xee, 0x36, 0x10,
   0x6e, 0x18, 0x46, 0xa6, 0x22, 0x88, 0x13, 0xf7, 0x2d, 0xb8, 0x0e, 0x3d, 0xf5, 0xa4, 0x39, 0x3b,
   0x07, 0x9e, 0x9c, 0x9d, 0x59, 0x9f, 0x1b, 0x08, 0x90, 0x09, 0x7a, 0x1c, 0xea, 0xa0, 0x71, 0x5a,
   0xd1, 0x1d, 0xc3, 0x7b, 0xae, 0x0a, 0xa9, 0x91, 0x51, 0x5b, 0x76, 0x72, 0x85, 0xa1, 0x49, 0xeb,
   0xcb, 0x7c, 0xfd, 0xc4, 0xdb, 0x1e, 0x8b, 0xd2, 0xd7, 0x92, 0x55, 0xaa, 0x43, 0x0b, 0x25, 0xaf,
   0xc0, 0x73, 0x99, 0x77, 0x96, 0x5c, 0xfa, 0x52, 0xe4, 0xec, 0x5f, 0x4a, 0xb6, 0xa2, 0x16, 0x86,
   0x69, 0xc5, 0x62, 0xfe, 0x29, 0x7d, 0xbb, 0xcc, 0xe0, 0xd3, 0x4d, 0x8c, 0xf2, 0x1f, 0x30, 0xdc,
   0x82, 0xab, 0xe7, 0x56, 0xb3, 0x93, 0x40, 0xd8, 0x34, 0xb0, 0xef, 0x26, 0x37, 0x0c, 0x11, 0x44,
   0x6f, 0x78, 0x19, 0x9a, 0x47, 0x74, 0xa7, 0xc1, 0x23, 0x53, 0x89, 0xfb, 0x14, 0x5d, 0xf8, 0x97,
   0x2e, 0x4b, 0xb9, 0x60, 0x0f, 0xed, 0x3e, 0xe5, 0xf6, 0x87, 0xa5, 0x17, 0x3a, 0xa3, 0x3c, 0xb7,

  } ;