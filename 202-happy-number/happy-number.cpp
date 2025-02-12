class Solution {
public:
    bool isHappy(int n) {
        if(n&0x80000000){
            return false;
        }
        unordered_map<int,int> sums;
        int sum = 0;
        while(n != 1){
            sum = 0;
            while(n != 0){
                sum += (n%10)*(n%10);
                n = n/10;
            }
            if(++sums[sum] > 1){
                return false;
            }
            n = sum;
        }
        return true;
    }
};