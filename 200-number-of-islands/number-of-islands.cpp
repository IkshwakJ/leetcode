enum direc{
    N = 0,
    W,
    E,
    S,
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        init_islands(); //initiallizes the entire grid to 0

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' && islands[i][j] == 0)
                    which_island(grid, i, j);
            }
        }
        // island_count = 0;
        // int temp = 0;
        // for(int i = 0; i<m; i++)
        // {
        //     for(int j = 0; j<n; j++){
        //         // if(islands[i][j]>temp){
                    
        //         //     temp =islands[i][j];
        //         //     island_count++;
        //         // }
        //         cout<<setw(3)<<islands[i][j];
        //         if (j!=n-1)
        //             cout<<", ";
        //         else
        //             cout<<";";
        //     }
        //     cout<<"\n";
        // }
        return island_count;
    }
private:

    int m = 0; //rows
    int n = 0; //columns
    int island_count = 0;
    int max_cnt = 0;
    vector<vector<int>> islands;

    void init_islands();
    void which_island(vector<vector<char>>& map, int x, int y);
    void merge_islands(int a, int b);
};

void Solution :: which_island(vector<vector<char>>& map, int x, int y){
    
    for(int dir = 0; dir<4; dir++)
        switch(dir){
           
            case N:
                if(x > 0){
                    if (islands[x-1][y] != 0){
                        if (islands[x][y] != 0){
                            if(islands[x][y] != islands[x-1][y])
                                merge_islands(islands[x][y],islands[x-1][y]);
                        }
                        else
                            islands[x][y] = islands[x-1][y];
                    }
                }
                break;
            case W:
                if(y > 0){
                    if (islands[x][y-1] != 0){
                        if (islands[x][y] != 0){
                            if(islands[x][y] != islands[x][y-1])
                                merge_islands(islands[x][y],islands[x][y-1]);
                        }
                        else
                            islands[x][y] = islands[x][y-1];
                    }
                }
                break;
            case E:
                if(y < n-1){
                    if (islands[x][y+1] != 0){
                        if (islands[x][y] != 0){
                            if(islands[x][y] != islands[x][y+1])
                                merge_islands(islands[x][y],islands[x][y+1]);
                        }
                        else
                            islands[x][y] = islands[x][y+1];
                    }
                }
                break;
            case S:
                if(x < m-1){
                    if (islands[x+1][y] != 0){
                        if (islands[x][y] != 0){
                            if(islands[x][y] != islands[x+1][y])
                                merge_islands(islands[x][y],islands[x+1][y]);
                        }
                        else
                            islands[x][y] = islands[x+1][y];
                    }
                }
                break;
        }
        
        if(islands[x][y] == 0){
            max_cnt++;
            islands[x][y] = max_cnt;
            island_count++;

        }
}

void Solution :: merge_islands(int a, int b){
    if(a > b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
    for(int i=0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(islands[i][j] == b)
                islands[i][j] = a;
        }
    }
    island_count--;
}
void Solution :: init_islands(){
    for(int i = 0; i<m; i++)
        {
            vector<int> temp;
            for(int j = 0; j<n; j++){
                temp.push_back(0);
            }
            islands.push_back(temp);
        }
}