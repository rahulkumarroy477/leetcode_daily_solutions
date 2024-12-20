class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // push 1 at start and end to avoid complexity at edge case
        nums.insert(nums.begin(),1);    // O(N)
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2,0));

        for(int i = n;i>0; i--){
            for(int j = i; j<=n;j++){

                int maxi = INT_MIN;
                for(int k = i; k<=j; k++){
                    int coins = nums[i-1] * nums[k] * nums[j+1];
                    int remCoins = dp[i][k-1] + dp[k+1][j];

                    maxi = max(maxi, coins + remCoins);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
        
    }
};