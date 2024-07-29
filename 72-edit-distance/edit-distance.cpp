class Solution {

int t[501][501];
int solve(int i, int j, string s1, string s2){
    // s1 becomes empty then s1="" and s2 = "abc" to convert s1 to s2 we will perform
    // 3 insert operations i.e.., return j + 1
    if(i==0) return j;

    // if s2 becomes empty s2="" and s1="abc"   need 3 delete operations
    if(j==0) return i;

    if(t[i][j]!=-1) return t[i][j];

    if(s1[i-1]==s2[j-1]){
        return t[i][j] =  solve(i-1,j-1,s1,s2);
    }

    // insert a character   s1 = "abc" s2="abcd"
    int insertion = solve(i,j-1,s1,s2);
    int deletion = solve(i-1,j,s1,s2);
    int replace = solve(i-1,j-1,s1,s2);

    return t[i][j] =  1 + min({insertion,deletion,replace});
    
}
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // memset(t,-1,sizeof(t));
        // return solve(m,n,word1,word2);

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i = 0;i<=n;i++){
            dp[0][i] = i;
        }
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }

        return dp[m][n];
    }
};