// #include<cmath>
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> result (right+1,0);
        int i = left;
        int temp, set_bit_cnt;
        int number_of_primes = 0;
        int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
        while (left <= right) {
            temp = left;
            set_bit_cnt = 0;
            while(temp){
                set_bit_cnt++;
                temp &= (temp - 1);
            }
            for(int j = 0; j < 11; j++){
                if(set_bit_cnt == primes[j]){
                    number_of_primes ++;
                }
            }
            left++;
        }
        return number_of_primes;
    }
};