class Solution {
public:
    int divide(int dividend, int divisor) {
        int quo = 0;
        long num = abs((long)dividend);
        long den = abs((long)divisor);
        int curr;
        if(divisor == -1 && dividend == INT_MIN){
            return INT_MAX;
        }
        else if(divisor == 1 && dividend == INT_MIN){
            return INT_MIN;
        }
        while(num>=den){
            curr = 0;
            while(den<<curr <= num){
                curr++;
            }
            quo |= 1<<(--curr);
            num -= den<<(curr);
        }
        if ((dividend < 0) ^ (divisor < 0)) {
            quo = -quo;
        }
        return quo;
    }
};