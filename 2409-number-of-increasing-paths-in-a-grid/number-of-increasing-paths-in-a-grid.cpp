class Solution {
public:
    int m, n;
    int MOD = 1e9 + 7;

    vector<vector<int>> dp;
    bool isSafe(int i, int j){
        return (i>=0 and j>=0 and i<m and j<n);
    }
    
    vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    int solve(vector<vector<int>>& grid, int i, int j){

        if(dp[i][j] != -1)  return dp[i][j];
        int count = 1;

        for(auto [di,dj]: dir){
            int ni = i + di;
            int nj = j + dj;

            if(isSafe(ni,nj) && grid[ni][nj] < grid[i][j]){
                count = (count + solve(grid, ni, nj))%MOD;
            }
        }

        return dp[i][j] = count%MOD;

    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                res = (res + solve(grid,i,j))%MOD;
            }
        }

        return res%MOD;
    }
};