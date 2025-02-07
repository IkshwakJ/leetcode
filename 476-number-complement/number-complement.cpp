class Solution {
public:
    int findComplement(int num) {
        if (num == INT_MAX)
            return 0;
        int result = ~num;
        int count = 0;
        while(num){
            num = num>>1;
            count++;
        }
        return result^((~0)<<count);
    }
};