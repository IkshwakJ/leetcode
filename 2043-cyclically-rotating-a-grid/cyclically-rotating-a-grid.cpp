class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        if (rows == 0) return {};
        int cols = grid[0].size();

        for (int layer = 0; layer < min(rows, cols) / 2; layer++) {

            int top = layer;
            int left = layer;
            int bottom = rows - layer - 1;
            int right = cols - layer - 1;

            vector<int> loop;

            // ---- Extract layer CCW ----
            int m = top, n = left;
            int dir[2] = {0, 1};   // start right

            int perimeter = 2 * (bottom - top + right - left);

            for (int step = 0; step < perimeter; step++) {
                loop.push_back(grid[m][n]);

                int next_m = m + dir[0];
                int next_n = n + dir[1];

                if (next_n > right) {        // go down
                    dir[0] = 1; dir[1] = 0;
                }
                else if (next_m > bottom) {  // go left
                    dir[0] = 0; dir[1] = -1;
                }
                else if (next_n < left) {    // go up
                    dir[0] = -1; dir[1] = 0;
                }
                else if (next_m < top) {     // go right
                    dir[0] = 0; dir[1] = 1;
                }

                m += dir[0];
                n += dir[1];
            }

            // ---- ROTATE ----
            int kk = k % loop.size();     // <-- FIX: per-layer rotation amount
            vector<int> rotated(loop.size());

            for (int i = 0; i < loop.size(); i++) {
                rotated[i] = loop[(i + kk) % loop.size()];
            }

            // ---- WRITE BACK ----
            m = top;
            n = left;
            dir[0] = 0;
            dir[1] = 1;

            for (int step = 0; step < perimeter; step++) {
                grid[m][n] = rotated[step];

                int next_m = m + dir[0];
                int next_n = n + dir[1];

                if (next_n > right) {
                    dir[0] = 1; dir[1] = 0;
                }
                else if (next_m > bottom) {
                    dir[0] = 0; dir[1] = -1;
                }
                else if (next_n < left) {
                    dir[0] = -1; dir[1] = 0;
                }
                else if (next_m < top) {
                    dir[0] = 0; dir[1] = 1;
                }

                m += dir[0];
                n += dir[1];
            }
        }

        return grid;
    }
};
