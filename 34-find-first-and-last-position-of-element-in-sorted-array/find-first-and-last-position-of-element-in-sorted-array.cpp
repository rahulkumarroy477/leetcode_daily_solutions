class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int idx = -1;
        int l = 0, r = nums.size()-1;
        bool found = binary_search(nums.begin(),nums.end(),target);
        vector<int> ans;
        if(found){
            int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            ans.push_back(lb);
            if(lb==nums.size()-1)   return {lb,lb};
            int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(lb!=ub and nums[ub-1]==nums[lb]) ans.push_back(ub-1);  
        }
        else return {-1,-1};
        return ans;
        
    }
};