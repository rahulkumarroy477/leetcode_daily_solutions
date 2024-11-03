class Solution {
public:
    int m,n;
    bool isSafe(int i, int j){
        return (i>=0 and j>=0 and i<m and j<n);
    }

    vector<vector<int>> dp;
    vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    int solve(vector<vector<int>>& grid, int i, int j){

        if(dp[i][j] != -1)  return dp[i][j];
        int ans = 1;

        for(auto [di,dj]: dir){
            int ni = i + di;
            int nj = j + dj;

            if(isSafe(ni,nj) && grid[ni][nj] < grid[i][j]){
                ans = max(ans, 1 + solve(grid, ni, nj));
            }
        }

        return dp[i][j] = ans;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.resize(m,vector<int>(n,-1));
        int res = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                res = max(res, solve(matrix,i,j));
            }
        }

        return res;
    }
};