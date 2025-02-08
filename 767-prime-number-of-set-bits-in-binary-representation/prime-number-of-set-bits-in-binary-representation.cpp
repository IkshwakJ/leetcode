// #include<cmath>
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> result (right+1,0);
        int i = 1;
        int number_of_primes = 0;
        int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
        while (i <= right) {
            result[i] = result[i&(i-1)] + 1;
            /*
                i&(i-1) will give the last / nearest index to which there is only a difference of 1 bit.
                We start at index 0 which has 0 set bit and index 1 is closest to index 0 seperated by one bit.
                Example index 76 which is 1001100 in binary is just one bit seprated from index 72 which is 1001000.
                76&75 will result in 72.
            */
            if(i >= left){
                for(int j = 0; j < 11; j++){
                    if(result[i] == primes[j]){
                        number_of_primes ++;
                    }
                }
            }
            i++;
        }
        return number_of_primes;
    }
};