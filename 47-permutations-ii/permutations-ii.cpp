class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        solve(0, nums, ans);
        return ans;
    }
    
    void solve(int idx, std::vector<int>& nums, std::vector<std::vector<int>>& ans) {
        int n = nums.size();
        if (idx == n) {
            ans.push_back(nums);
            return;
        }
        std::unordered_set<int> st;
        for (int i = idx; i < n; i++) {
            if(st.count(nums[i])==1)    continue;   // already in the set
            
            std::swap(nums[i], nums[idx]); // Swap
            
            solve(idx + 1, nums, ans);     // Recurse
            std::swap(nums[i], nums[idx]); // Undo swap
            st.insert(nums[i]);
        }
    }
};