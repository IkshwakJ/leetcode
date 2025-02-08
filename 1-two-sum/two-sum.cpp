class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices {2,0};
        int len = nums.size();
        for(int i = 0; i<len; i++){
            for(int j = i+1; j<len; j++){
                if(nums[i]+nums[j] == target){
                    indices[0] = i;
                    indices[1] = j;
                }
            }
        }    
        return indices;
    }
};