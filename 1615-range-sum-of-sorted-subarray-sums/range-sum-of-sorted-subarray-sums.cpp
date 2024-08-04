class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        const int MOD = 1e9+7;

        for(int length = 1;length<=n;length++){
            int sum = 0;
            for(int i = 0;i<length;i++){
                sum = (sum + nums[i])%MOD;
            }
            ans.push_back(sum);
            for(int i = length;i<n;i++){
                sum -= nums[i-length];
                sum = (sum+nums[i])%MOD;
                ans.push_back(sum);
            }
        }

        sort(ans.begin(),ans.end());
        // for(int x:ans)  cout<<x<<" ";
        int sum = 0;
        for(int i = left-1;i<right;i++) sum = (sum+ans[i])%MOD;
        return sum;
    }
};