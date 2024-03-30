class Solution {
public:
    int sliding_window(vector<int>&nums,int k){
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        while(j<n){
            mp[nums[j]]++;
            
            // shrinking the window
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)  mp.erase(nums[i]);
                
                i++;
            }
            
            count += j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // if(k==1)    return nums.size();
        return sliding_window(nums,k) - sliding_window(nums,k-1);
    }
};