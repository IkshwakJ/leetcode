class Solution {
public:
    int mySqrt(int x) {
        long num = 0;
        long X = x;
        while(num*num < X){
            num++;
        }
        if(num*num == x){
            return num;
        }
        return --num;
    }
};