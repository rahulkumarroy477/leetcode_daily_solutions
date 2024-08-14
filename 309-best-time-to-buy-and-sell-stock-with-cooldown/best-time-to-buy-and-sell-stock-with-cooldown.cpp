class Solution {
    // int n;
    // int count = 0;
    // vector<vector<int>> dp;
    // int solve(int i, int buy, vector<int>&prices){
    //     if(i>=n)    return 0;
    //     count++;
    //     if(buy){
    //         return dp[i][buy] = max(-prices[i]+
    //         solve(i+1,0,prices),solve(i+1,1,prices));
    //     }
    //     return dp[i][buy] = max(prices[i]+
    //         solve(i+2,1,prices),solve(i+1,0,prices));   // cooldown can't sell on next day
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp.resize(n+1,vector<int>(2,-1));

        // int ans =  solve(0,1,prices);
        // cout<<count<<endl;
        // return ans;
        vector<vector<int>> dp(n+2,vector<int>(3,0));

        for (int i = n - 1; i >= 0; i--) {
            
            // Case when we do not hold a stock on day i
            dp[i][0] = max(-prices[i] + dp[i + 1][1],
            dp[i + 1][0]);
            
            // Case when we hold a stock on day i
            dp[i][1] = max(prices[i] + dp[i + 2][0],
            dp[i + 1][1]);
        }

        return dp[0][0];
    }
};