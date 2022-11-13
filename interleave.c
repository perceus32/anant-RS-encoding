#include "interleave.h"




void rs_encode_interleave(byte *data)
{
    byte rs_block[RS_BLOCK_LEN];
    byte codeword[RS_PACKET_LEN];
      for (byte i=0; i<INTERLEAVE_DEPTH; i++) 
      {

          // copy data from input to rs block
          
              for (byte j=0; j<RS_BLOCK_LEN; j++)
            {
    
                  rs_block[j] = data[i + (INTERLEAVE_DEPTH*j)];
            }

          // calculate parity data
              encode(rs_block);   // use_dual_basis
           
          // data into output array
              for (byte j=0; j<RS_BLOCK_LEN; j++)
                  codeword[i + (INTERLEAVE_DEPTH*j)] = rs_block[j];
          
      }
      rand_drand(codeword);
      memcpy(data, codeword, 1275);
      
}
