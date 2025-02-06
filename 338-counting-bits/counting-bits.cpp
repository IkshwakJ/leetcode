class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result (n+1, 0);
        int i = 1;
        while (i <= n) {
            result[i] = result[i&(i-1)] + 1;
            /*
                i&(i-1) will give the last / nearest index to which there is only a difference of 1 bit.
                We start at index 0 which has 0 set bit and index 1 is closest to index 0 seperated by one bit.
                Example index 76 which is 1001100 in binary is just one bit seprated from index 72 which is 1001000.
                76&75 will result in 72.
            */
            i++;
        }
        return result;
    }
};