class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result (1<<nums.size());
        for(int i = 0; i < 1<<nums.size(); i++){
            vector<int> row;
            for(int j = 0; j < nums.size(); j++){
                if(i&(1<<j)){
                    row.push_back(nums[j]);
                }
            }
            result[i] = row;
        }
        return result;
    }
};