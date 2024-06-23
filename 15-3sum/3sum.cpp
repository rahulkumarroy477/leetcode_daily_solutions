class Solution {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(N2)
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int twoSum = -nums[i];
            // two pointer
            int st = i+1;
            int end = n-1;
            while(st<end){
                int currSum = nums[st] + nums[end];
                if(currSum == twoSum){
                    ans.push_back({nums[i],nums[st],nums[end]});
                    while(st<end and nums[st]==nums[st+1])  st++;   // skip duplicates
                    while(st<end and nums[end] == nums[end-1])  end--;
                    st++;
                    end--;
                }
                else if(currSum < twoSum)   
                    st++;
                else
                    end--;
            }
        }
        return ans;
    }
};