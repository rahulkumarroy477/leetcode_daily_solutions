class Solution {
    // int n;
    // int t[101];
    // int solve(int idx,vector<int> &nums){
    //     if(idx>=n)  return 0;

    //     if(t[idx]!=-1)  return t[idx];
    //     // take
    //     int take = nums[idx] + solve(idx+2,nums);
    //     int nottake = solve(idx+1,nums);

    //     return t[idx] = max(take,nottake);
    // }
public:
    int rob(vector<int>& nums) {
        // n = nums.size();
        // memset(t,-1,sizeof(t));
        // return solve(0,nums);
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0]; // single house
        for(int i = 2;i<=n;i++){
            int take = nums[i-1] + dp[i-2];
            int nottake = dp[i-1];

            dp[i] = max(take,nottake); 
        }

        return dp[n];
    }
};