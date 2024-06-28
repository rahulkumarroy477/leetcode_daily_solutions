class Solution {
public:
    // int ans = 0;
    // void upDirection(int row,int col,vector<vector<int>>& grid,int cherryCollected){
    //     if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==-1){
    //         return;
    //     }

    //     if(row==0 && col==0){
    //         ans = max(ans,cherryCollected);
    //         return;
    //     }
    //     int cherries = grid[row][col];
    //     grid[row][col] = 0;

    //     upDirection(row-1,col,grid,cherryCollected+cherries);
    //     upDirection(row,col-1,grid,cherryCollected+cherries);

    //     grid[row][col] = cherries;
    // }
    // void downDirection(int row,int col,vector<vector<int>>& grid,int cherryCollected){
    //     if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==-1){
    //         return;
    //     }

    //     if(row == grid.size()-1 && col==grid[0].size()-1){
    //         upDirection(row,col,grid,cherryCollected);
    //     }
    //     int cherries = grid[row][col];
    //     grid[row][col] = 0;

    //     downDirection(row+1,col,grid,cherryCollected+cherries);
    //     downDirection(row,col+1,grid,cherryCollected+cherries);

    //     grid[row][col] = cherries;
    // }
    
    int dp[51][51][51];

    int solve(int r1, int c1, int r2, int N, std::vector<std::vector<int>> &grid) {
        int c2 = r1 + c1 - r2;

        // boundary conditions
        if (r1 >= N || r2 >= N || c1 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        // base case 
        if (r1 == N - 1 && c1 == N - 1)
            return grid[r1][c1];

        // already answer in dp
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        // pick the cherries
        int cherries = grid[r1][c1];
        if (r1 != r2)
            cherries += grid[r2][c2];
        
        // traverse in all possible directions
        cherries += std::max({solve(r1 + 1, c1, r2 + 1, N, grid), 
                        solve(r1, c1 + 1, r2 + 1, N, grid),
                        solve(r1 + 1, c1, r2, N, grid), 
                        solve(r1, c1 + 1, r2, N, grid)});

        
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(std::vector<std::vector<int>>& grid) {
        int N = grid.size();
        if (N == 1 && grid[0][0] == 1) {
            return 1;
        }

        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0, 0, N, grid);
        return result < 0 ? 0 : result;
    }
};