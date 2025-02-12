class Solution {
public:
    bool isHappy(int n) {
        if(n&0x80000000){
            return false;
        }
        int slow = n;
        int fast = n;
        do{
            slow = squared_sum_of_digits(slow);
            fast = squared_sum_of_digits(squared_sum_of_digits(fast));
        }while(slow != fast);
        if(slow == 1){
            return true;
        }
        return false;
    }
    int squared_sum_of_digits(int x){
        int sum = 0;
        while(x != 0){
            sum += (x%10)*(x%10);
            x /= 10;
        }
        return sum;
    }
};