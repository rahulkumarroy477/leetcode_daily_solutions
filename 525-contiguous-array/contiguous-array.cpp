class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // assume 0 to be -1
        unordered_map<int,int> mp;
        
        // find longest subarray with sum = 0
        mp[0] = -1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0)  sum += -1;
            else sum += 1;
            
            if(mp.find(sum)!=mp.end()){
                ans = max(ans,i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        
        return ans;
        
    }
};