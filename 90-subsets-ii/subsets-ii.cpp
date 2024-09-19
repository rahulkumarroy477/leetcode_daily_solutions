class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int>&nums, vector<int> &temp){
        ans.push_back(temp);

        for(int i = idx;i<nums.size();i++){
            if(i!=idx and nums[i]==nums[i-1])   continue;

            temp.push_back(nums[i]);
            solve(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> temp;
        solve(0,nums,temp);

        return ans;
    }
};