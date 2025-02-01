class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int result = nums[0];
        for(int i = 1 ; i < len; i++){
            result = result^nums[i]; // When a number is XOR'ed with itself it returns 0 (bitwise),
                                     // If the array has a number that is not repeated then that number will
                                     // be the final value. 
                                     // This works only if all other numbers are repeated in multiples of 2.
        }
        return result;
    }
};