class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // This is a slightly optimized brute force method. 
        int n = nums.size();
        int result = 0;
        for(int i = 0; i<n; i++){
            result ^= nums[i]^i;
        }
        return result^n;
    }
};