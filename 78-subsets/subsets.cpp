class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int possible = pow(2,nums.size());
        vector<vector<int>> result;
        for(int i = 0; i < possible; i++){
            vector<int> row;
            for(int j = 0; j < len; j++){
                if(i&1<<j){
                    row.push_back(nums[j]);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};