class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            n &= (n - 1); // This action removes the last/rightmost setbit. 
            count++;
        }

        return count;
    }
};