class Solution {
typedef long long ll;

// long long t[100001][2];
// int n;
// ll solve(int idx, bool flag,vector<int> &nums){
//     if(idx >= n)  return 0;

//     if(t[idx][flag]!=-1)    return t[idx][flag];
//     ll skip = solve(idx+1,flag,nums);

//     ll val = nums[idx];
//     if(!flag){
//         val = -val;
//     }

//     ll take = val + solve(idx+1,!flag,nums);

//     return t[idx][flag] = max(skip,take);
// }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // n = nums.size();
        // memset(t,-1,sizeof(t));
        // return solve(0,true,nums);
        int n = nums.size();

        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        for(int i = 1;i<=n;i++){
            // even length
            dp[i][0] = max(
                -nums[i-1] + dp[i-1][1],
                dp[i-1][0]
            );
            // odd length

            dp[i][1] = max(
                nums[i-1]+dp[i-1][0],
                dp[i-1][1]
            );
        }

        return max(dp[n][0],dp[n][1]);
    }
};