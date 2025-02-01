class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        int len = nums.size();
        for(int i = 0; i<len; i++){
            sum += nums[i];
            if (max_sum < sum){
                max_sum = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return max_sum;
    }
}; 