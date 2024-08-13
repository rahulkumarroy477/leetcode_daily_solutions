class Solution {
    int N;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i >= N || j<0 || j>=N)   return INT_MAX;

        if(i==N-1)  return matrix[i][j];

        if(dp[i][j]!=-1)    return dp[i][j];
        int down = solve(i+1,j,matrix);
        int diag1 = solve(i+1,j-1,matrix);
        int diag2 = solve(i+1,j+1,matrix);

        return dp[i][j] = matrix[i][j] + min({down,diag1,diag2});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        N = matrix.size();

        if(N==1)    return matrix[0][0];
        // dp.resize(N+1,vector<int>(N+1,-1));
        // int minPathSum = INT_MAX;


        // // Start the recursion from any cell in the first row
        // for (int j = 0; j < N; j++) {
        //     minPathSum = min(minPathSum, solve(0, j, matrix));
        // }

        // return minPathSum;

        vector<vector<int>> dp(N,vector<int>(N,0));
        dp[0] = matrix[0];
        for(int i = 1;i<N;i++){
            for(int j = 0;j<N;j++){
                if (j == 0) {
                dp[i][j] = matrix[i][j] + 
                    min(dp[i-1][j], dp[i-1][j+1]);
                } else if (j == N - 1) {
                    dp[i][j] = matrix[i][j] + 
                    min(dp[i-1][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = matrix[i][j] + 
                    min({dp[i-1][j], dp[i-1][j-1], 
                    dp[i-1][j+1]});
                }
            }
            
            
        }

        return *min_element(dp[N-1].begin(),dp[N-1].end());
    }
};