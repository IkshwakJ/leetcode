class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int len = nums.size();
        for(int i = 0; i<len; i++){
            ones = (ones^nums[i])&(~twos);
            twos = (twos^nums[i])&(~ones);
        }    
        return ones;
    }
};