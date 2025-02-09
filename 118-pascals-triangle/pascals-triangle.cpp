class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0){
            return {};
        }
        if(numRows >= 1){
            result.push_back({1});
        }
        if(numRows >= 2){
            result.push_back({1,1});
        }
        
        for(int i = 3; i <= numRows; i++){
            vector<int> row;
            for(int j = 0; j < i; j++){
                if(j == 0 || j == i - 1){
                    row.push_back(1);
                }
                else{
                    row.push_back(result[i-2][j-1] + result[i-2][j]);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};