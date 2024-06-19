class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];

            int cumSum = sum - k;
            if(mp.find(cumSum)!=mp.end()){
                ans += mp[cumSum];
            }
            mp[sum]++;
        }
        return ans;
    }
};