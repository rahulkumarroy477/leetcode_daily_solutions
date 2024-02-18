class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> dp(cols);
        dp[0] = grid[0][0];
        for(int i = 1;i<cols;i++)   dp[i] = dp[i-1] + grid[0][i];
        
        for(int i = 1;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(j!=0){
                    dp[j] = grid[i][j] + min(dp[j-1],dp[j]);
                }
                else dp[j] += grid[i][j];
            }
        }
        return dp[cols-1];
    }
};