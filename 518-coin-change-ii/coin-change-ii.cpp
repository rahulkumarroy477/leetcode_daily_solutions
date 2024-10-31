class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int amount, vector<int> &coins){
        if(idx == coins.size() || amount < 0) return 0;

        if(amount == 0) return 1;

        if(dp[idx][amount] != -1)   return dp[idx][amount];
        int notPick = solve(idx+1, amount, coins);
        int pick = solve(idx, amount-coins[idx], coins);

        return dp[idx][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0, amount, coins);
    }
};