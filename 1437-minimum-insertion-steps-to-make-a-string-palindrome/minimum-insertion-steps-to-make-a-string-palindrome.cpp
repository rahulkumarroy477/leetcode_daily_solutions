class Solution {
public:
    int minInsertions(string s) {
        // check the length of longest palindromic subsequence, lps
        // now we need len - lps to make it palindrome


        int n = s.length();
        
        string t(s.begin(),s.end());
        reverse(s.begin(),s.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return n - dp[n][n];
    }
};