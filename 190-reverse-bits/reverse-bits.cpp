class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n&0xffff0000)>>16 | (n&0x0000ffff)<<16; // Move 16 bits right end to the left and viceversa .
        n = (n&0xff00ff00)>>8 | (n&0x00ff00ff00ff)<<8; // Move alternating sets of 8 bits 
                                                       // starting from the right to the left and viceversa.
        n = (n&0xf0f0f0f0)>>4 | (n&0x0f0f0f0f0f0f)<<4; // Move alternating sets of 4 bits 
                                                       // starting from the right to the left and viceversa.
        n = (n&0xCCCCCCCC)>>2 | (n&0x33333333)<<2; // Move alternating sets of 2 bits 
                                                   // starting from the right to the left and viceversa.
        n = (n&0xAAAAAAAA)>>1 | (n&0x55555555)<<1; // Move alternating bits starting from the right to the left and viceversa.
        return n;
    }
};