class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        
        for (int i = 0; i < (1 << len); i++) {
            vector<int> row;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    row.push_back(nums[j]);
                }
            }
            
            bool isDuplicate = false;
            for (int k = 0; k < result.size(); k++) {
                if (areEqual(result[k], row)) {
                    isDuplicate = true;
                    break;
                }
            }
            
            if (!isDuplicate) {
                result.push_back(row);
            }
        }

        return result;
    }

private:
    bool areEqual(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;

        vector<int> visited(b.size(), 0); 

        for (int i = 0; i < a.size(); i++) {
            bool found = false;
            for (int j = 0; j < b.size(); j++) {
                if (a[i] == b[j] && !visited[j]) {
                    visited[j] = 1; 
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};