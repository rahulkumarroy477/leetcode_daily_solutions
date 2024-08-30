class Solution {

    vector<int> dp;
    int solve(int i, vector<int>&arr, int k){
        int n = arr.size();

        if(i==n)    return 0;

        if(dp[i] != -1) return dp[i];
        int maxCost = INT_MIN;
        int maxi = INT_MIN;
        for(int j = i;j<i+k && j<n;j++){
            maxi = max(maxi,arr[j]);
            int cost = maxi*(j-i+1) + solve(j+1,arr, k);
            maxCost = max(maxCost,cost);
        }

        return dp[i] = maxCost;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n,-1);

        return solve(0,arr,k);
    }
};