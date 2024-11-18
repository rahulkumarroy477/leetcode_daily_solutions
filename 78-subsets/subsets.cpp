class Solution {
public:
    void solve(int idx, vector<int> &temp,
    vector<vector<int>> &ans, vector<int> &nums){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[idx]);
        solve(idx+1, temp, ans, nums);
        temp.pop_back();
        solve(idx+1, temp, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> temp;
        vector<vector<int>> ans;

        solve(0, temp, ans, nums);
        return ans;
    }
};