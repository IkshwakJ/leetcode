class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n;
        if(m){
            n = matrix[0].size();    
        }
        else{
            return false;
        }
        int row = m - 1;
        int column = n - 1;
        while(row >= 0 && column >= 0){
            if(matrix[row][0] > target){
                row--;
            }
            else if(matrix[row][column] > target){
                column--;
            }
            else if(matrix[row][column] == target){
                return true;
            }
            else{
                row = -1;
                column = -1;
                break;
            }
        }
        return false;    
    }
};