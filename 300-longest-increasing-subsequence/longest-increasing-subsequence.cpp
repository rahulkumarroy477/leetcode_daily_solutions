class Solution {


int solve(int idx, int prev, int n, vector<int>&nums,vector<vector<int>> &dp){
    if(idx == n)    return 0;

    if(dp[idx][prev+1]!=-1)  return dp[idx][prev+1];
    // not take
    int ans = solve(idx+1,prev,n,nums,dp);

    if(prev == -1 || nums[idx]>nums[prev])
        ans = max(ans, 1 + solve(idx+1,idx,n,nums,dp));
    
    return dp[idx][prev+1] = ans;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // memset(t,-1,sizeof(t));
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};