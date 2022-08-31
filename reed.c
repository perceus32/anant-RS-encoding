generate_gf(void)
{
    int i;
    gf mask;
    char *Pp =  allPp[GF_BITS] ;

    mask = 1;
    gf_exp[GF_BITS] = 0;
    for (i = 0; i < GF_BITS; i++, mask <<= 1 ) {
    gf_exp[i] = mask;
    gf_log[gf_exp[i]] = i;
    if ( Pp[i] == '1' )
        gf_exp[GF_BITS] ^= mask;
    }
    gf_log[gf_exp[GF_BITS]] = GF_BITS;
    mask = 1 << (GF_BITS - 1 ) ;
    for (i = GF_BITS + 1; i < GF_SIZE; i++) {
    if (gf_exp[i - 1] >= mask)
        gf_exp[i] = gf_exp[GF_BITS] ^ ((gf_exp[i - 1] ^ mask) << 1);
    else
        gf_exp[i] = gf_exp[i - 1] << 1;
    gf_log[gf_exp[i]] = i;
    }
    gf_log[0] = GF_SIZE ;
    for (i = 0 ; i < GF_SIZE ; i++)
    gf_exp[i + GF_SIZE] = gf_exp[i] ;
    inverse[0] = 0 ;
    inverse[1] = 1;
    for (i=2; i<=GF_SIZE; i++)
    inverse[i] = gf_exp[GF_SIZE-gf_log[i]];
}
