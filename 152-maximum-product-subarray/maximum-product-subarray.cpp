class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = INT_MIN;
        long long pre = 1, suff = 1;
        for(int i = 0;i<n;i++){
            if(pre == 0 || abs(pre) > INT_MAX)    pre = 1;
            if(suff == 0 || abs(suff) > INT_MAX)   suff = 1;
            pre = pre * nums[i];
            suff = suff * nums[n-i-1] * 1LL;
            ans = max(ans,max(pre,suff));
        }


        return ans;
    }
};