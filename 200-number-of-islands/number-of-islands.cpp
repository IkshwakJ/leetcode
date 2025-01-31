// Breadth First Search
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); // Number of Rows
        n = grid[0].size(); // Number of = Columns 
        for(int j = 0; j<n; j++){
            for(int i  = 0; i<m; i++){
                if(grid[i][j] == '1'){
                    total_island_count++;
                    mark_path_to_zero(grid, i, j);
                }
            }
        }
        return total_island_count;
    }
private:
int m, n, total_island_count = 0;
void mark_path_to_zero(vector<vector<char>>& input, int x, int y){
    if(x<0 || x>=m || y<0 || y>= n || input[x][y] =='0'){
        return;
    }
    else{
        input[x][y] = '0';
        mark_path_to_zero(input, x, y+1);
        mark_path_to_zero(input, x, y-1);
        mark_path_to_zero(input, x+1, y);
        mark_path_to_zero(input, x-1, y);
    }
}
};