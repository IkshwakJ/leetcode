class Solution {
public:
    bool isPowerOfTwo(int n) {
        // In powers of 2 there is only one set bit
        long N = n; // using long to overcome the overflow issue.
        if(N&(N-1) || n == 0) // n&(n-1) will always remove the rightmost set bit. n condition is to remove the 0 case.
            return 0;
        return 1;
    }
};