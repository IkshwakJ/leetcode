class Solution {
public:
    bool isPowerOfFour(int n) {
        long N = n;
        if (n == 0)
            return false;

        if(N&(N-1))
            return false; // Powers of 2 will become 0 after N&(N-1).
        
        if(n&0x55555555) // Mask to set powers of 2 that are not powers of 4 to 0.
            return true;
        
        return false;
    }
};