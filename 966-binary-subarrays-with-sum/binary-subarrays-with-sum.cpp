class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for(const auto &x:nums){
            sum += x;
            // already cumulative sum in map
            int cum_sum = sum-goal;
            
            if(mp.find(cum_sum)!=mp.end()){
                ans += mp[cum_sum];
            }
            mp[sum]++;
            
        }
        
        return ans;
    }
};