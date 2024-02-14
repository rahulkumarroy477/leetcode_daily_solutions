class Solution {
public:
    int jump(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i<n-1;i++){
            int curr = nums[i];
            for(int k = i+1;k<n and k<=i+curr;k++){
                dp[k] = min(dp[i]+1,dp[k]); 
            }
        }
        return dp[n-1];
        
    }
};