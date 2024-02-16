class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return true;
        
        // dp
        
//         vector<bool> dp(n,false);
//         dp[0] = true;
//         for(int i = 0;i<n;i++){
//             if(dp[i]==false)    continue;
//             for(int j = i+1;j<n and j<=nums[i]+i;j++){
//                 dp[j] = dp[j] or true;
//             }
            
//         }
//         return dp[n-1];
        
        // greedy
        
        int max_dist = 0;
        for(int i = 0;i<n;i++){
            if(max_dist<i)  return false;   // cannot reach to current index
            
            max_dist = max(max_dist,i+nums[i]);
            if(max_dist>=n-1)   return true;
        }
        return false;
    }
};