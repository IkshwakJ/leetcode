class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int len = nums.size();
        int possible = 1<<len;
        vector<vector<int>> result (possible);
        for(int i = 0; i < possible; i++){
            vector<int> row;
            for(int j = 0; j < len; j++){
                if(i&(1<<j)){
                    row.push_back(nums[j]);
                }
            }
            result[i] = row;
        }
        return result;
    }
};