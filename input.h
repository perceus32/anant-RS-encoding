#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>

typedef uint8_t byte;      

#define RS_PACKET_LEN 1275          //packet length after rs
#define NN 255
#define RS_DATA-LEN 223
#define INTERLEAVE_DEPTH 5
#define RS_PARITY_LEN 32
#define RS_BLOCK_LEN (RS_PARITY_LEN+RS_DATA_LEN)
