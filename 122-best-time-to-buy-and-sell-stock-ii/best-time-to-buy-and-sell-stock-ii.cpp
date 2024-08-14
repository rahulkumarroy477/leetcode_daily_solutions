class Solution {

    vector<vector<int>> dp;
    int n;
    int solve(int i, int buy, vector<int>& prices){
        if(i>=n)    return 0;
        
        if(dp[i][buy]!=-1)  return dp[i][buy];
        if(buy){
            return dp[i][buy] =  max(-prices[i]+solve(i+1,0,prices),
            solve(i+1,1,prices));
        }
        return dp[i][buy] = max(prices[i]+solve(i+1,1,prices),
        solve(i+1,0,prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n+1,vector<int>(3,-1));
        return solve(0,1,prices);
    }
};