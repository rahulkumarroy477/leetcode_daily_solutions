class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1 and grid[0][0] == 0) return 1;   
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;   // marking starting as visited
        // vector<vector<bool>> vis(n,vector<bool>(n,false));
        int count = 1;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();

                if(x == n-1 and y == n-1)   return count;

                for(int dx = -1;dx<=1;dx++){
                    for(int dy = -1;dy<=1;dy++){
                        int new_x = x + dx;
                        int new_y = y + dy;

                        if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < n and 
                            grid[new_x][new_y] == 0){
                            q.push({new_x, new_y});
                            grid[new_x][new_y] = 1;
                        }
                    }
                }
            }

            count++;
        }

        return -1;
        
    }
};