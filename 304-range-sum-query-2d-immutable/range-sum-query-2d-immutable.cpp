class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows < 1){
            return;
        }
        cols = matrix[0].size();
        sum_matrix.assign(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            vector<int> new_val;
            for(int j = 0; j < cols; j++){
                if(i == 0){
                    if(j == 0){
                        sum_matrix[0][0] = matrix[0][0];
                    }
                    else{
                        sum_matrix[i][j] = sum_matrix[i][j - 1] + matrix[i][j];
                    }
                }
                else{
                    if(j == 0){
                        sum_matrix[i][0] = sum_matrix[i-1][0] + matrix[i][j];
                    }
                    else{
                        sum_matrix[i][j] = sum_matrix[i-1][j] + sum_matrix[i][j-1] - sum_matrix[i-1][j-1] + matrix[i][j];
                    }
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(rows == -1 || cols == -1){
            return 0;
        }
        int sum = 0;
        if(row2 < rows && col2 < cols){
            sum = sum_matrix[row2][col2]; 
        }
        if(col1 != 0){
            sum -= sum_matrix[row2][col1 - 1];
        }
        if(row1 != 0){
            sum -= sum_matrix[row1 - 1][col2];
        }
        if(row1 != 0 && col1 != 0){
            sum += sum_matrix[row1 - 1][col1 - 1];
        }
        return sum;
    }
private: 
    int rows = -1;
    int cols = -1;
    vector<vector<int>> sum_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */