#include<stdint.h>
#include<stdio.h>
#include<string.h>
#include "reed_solomon.h"
#include "scramble.h"





#define RS_PACKET_LEN 1275          //packet length after rs
#define INTERLEAVE_DEPTH 5          //interleave depth 5
#define RS_DATA_LEN 223
#define RS_PARITY_LEN 32
#define RS_BLOCK_LEN (RS_DATA_LEN + RS_PARITY_LEN)



typedef uint8_t byte;               //renaming datatype
void rs_encode_interleave(byte *data);

