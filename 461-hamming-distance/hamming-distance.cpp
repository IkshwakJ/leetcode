class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x == y)
            return 0;
        int count = 0;
        int n = x^y;
        while (n) {
            n &= (n - 1); // This action removes the last/rightmost setbit. 
            count++;
        }
        return count;
    }
};