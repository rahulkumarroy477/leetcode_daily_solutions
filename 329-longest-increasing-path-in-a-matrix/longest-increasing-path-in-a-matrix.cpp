class Solution {

private:
    
    int m, n;
    int dp[201][201];
    vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
    int solve(int i, int j, vector<vector<int>> &matrix)
    {
        if(i>=m || i<0 || j>=n || j<0)    return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        // iterate in all directions
        int ans = 0;
        for(const auto &dir:directions){
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if(newI<m && newJ<n && newI>=0 && newJ>=0 and matrix[newI][newJ]>matrix[i][j]){
                ans = max(ans, 1+solve(newI,newJ,matrix));
            }

        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int dist = 1 + solve(i,j,matrix);
                ans = max(ans,dist);
            }
        }

        return ans;
    }
};