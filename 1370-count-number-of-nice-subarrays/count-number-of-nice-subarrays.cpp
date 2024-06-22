class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int oddCount = 0;
        int ans = 0;
        for(int i = 0;i<n; i++){
            if(nums[i]&1)   oddCount++;
            if(oddCount == k)   ans++;
            if(mp.find(oddCount-k)!=mp.end()){
                ans += mp[oddCount-k];
            }
            
            mp[oddCount]++;
        }
        
        return ans;
    }
};