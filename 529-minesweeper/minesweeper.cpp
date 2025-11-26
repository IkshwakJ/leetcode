class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int i = click[0];
        int j = click[1];
        int rows = board.size();
        if(rows < 1){
            return board;
        }
        int cols = board[0].size();
        if(board[i][j] == 'M'){
            board[i][j] = 'X';
            return board;
        }
        int m = 0;
        for(int dr = -1; dr <= 1; dr++){
            for(int dc = -1; dc <= 1; dc++){
                if(dr == 0 && dc == 0)
                    continue;
                int nr = i + dr; 
                int nc = j + dc;
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) 
                    continue;
                if (board[nr][nc] == 'M') m++;
            }
        }
        if(m > 0){
            board[i][j] = '0' + m;
            return board;
        }
        // If blank
        else
            board[i][j] = 'B';
        for(int dr = -1; dr <= 1; dr++){
            for(int dc = -1; dc <= 1; dc++){
                if(dr == 0 && dc == 0)
                    continue;
                int nr = i + dr; 
                int nc = j + dc;
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) 
                    continue;
                if(board[nr][nc] == 'E'){
                    vector<int> next = {nr, nc};
                    updateBoard(board, next);
                }
            }
        }
        return board;
    }
};