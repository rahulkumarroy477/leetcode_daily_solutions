class Solution {

// bool solve(int i, int j, string s, string p,vector<vector<int>> &dp){
//     if(j==0)    return i==0;
//     if(i==0){
//         for (int k = 1; k <= j; ++k) {
//                 if (p[k-1] != '*') return dp[i][j] = false;
//             }
//         return dp[i][j] = true;
//     }

//     if(dp[i][j] != -1) return dp[i][j];
//     // char matches

//     if(s[i-1]==p[j-1] || p[j-1]=='?'){
//         return dp[i][j] =  solve(i-1,j-1,s,p,dp);
//     }

//     // does not match
//     // 3 cases p[j-1] == '?' or '*' or any char
//     if (p[j-1] == '*') {
//         return dp[i][j] = solve(i, j-1, s, p, dp) || solve(i-1, j, s, p, dp);
//     }

//     return dp[i][j] = false;
//  }
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        // vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        // space optimization
        vector<bool> prev(n+1,false), curr(n+1,false);
        prev[0] = true;    // empty string and empty pattern
        for(int i = 1;i<=n;i++){
            if(p[i-1] == '*'){
                prev[i] = prev[i-1];
            }
        }

        for(int i = 1;i<=m;i++){
            curr[0] = false;
            for(int j = 1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j] = curr[j-1] || prev[j];
                }
                else    curr[j] = false;
            }

            prev = curr;
        }

        return prev[n];
    }
};