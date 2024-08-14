class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int i,int buy, int k,vector<int>& prices){
        if(i>=n)    return 0;
        if(k==0)    return 0;

        if(dp[i][buy][k]!=-1)   return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k] = max(-prices[i]+
            solve(i+1,0,k,prices),solve(i+1,1,k,prices));
        }
        return dp[i][buy][k] = max(prices[i]+
        solve(i+1,1,k-1,prices),solve(i+1,0,k,prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices);
    }
};