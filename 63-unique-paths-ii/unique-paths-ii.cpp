class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        
        vector<int> dp(m,0);
        dp[0] = !obstacleGrid[0][0];
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[0][i]) 
                break;
            dp[i] += dp[i-1];
        }
    
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++ ) {
                if(!obstacleGrid[i][j]) {
                    if( j != 0 )
                        dp[j] += dp[j - 1]; 
                } else dp[j] = 0;
            }
        }

        return dp[m - 1];
    }
};