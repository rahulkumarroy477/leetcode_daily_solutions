class Solution {

private:
    int m, n;
    vector<vector<bool>> vis;

    bool ok(int x, int y){
        return (x>=0 && x<m && y>=0 && y<n && !vis[x][y]);
    }
    
    //directions
    vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
    

    // dfs with size
    int dfs(int x, int y, vector<vector<int>> &grid){
        vis[x][y] = true;
        int count = 1;

        for(auto [dx,dy]:dir){
            int nx = x + dx;
            int ny = y + dy;

            if(ok(nx,ny) && grid[nx][ny]==1){
                count += dfs(nx,ny,grid);
            }
        }

        return count;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.resize(m,vector<bool>(n,false));

        // boundary marking
        for(int i = 0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if((i==0 || j == 0 || i==m-1 || j==n-1) && 
                grid[i][j] == 1 && !vis[i][j]){
                    dfs(i,j,grid);
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans += dfs(i,j,grid);
                }
            }
        }

        return ans;
    }
};