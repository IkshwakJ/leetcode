class Solution {
public:
    int countPrimeSetBits(int left, int right) {
         int temp, set_bit_cnt;
        int number_of_primes = 0;
        int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
        for(int i = left; i<=right; i++) {
            temp = i;
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
        }
        return number_of_primes;
    }
};