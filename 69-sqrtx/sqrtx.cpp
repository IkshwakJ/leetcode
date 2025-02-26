class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        long left = 1;
        long right = x - 1;
        long ans = 0;
        while(left <= right){
            long mid = (left + right)/2;
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return ans; 
    }
};