class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    int n;
    void solve(int idx,int target, vector<int>& nums){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;   // skip duplicates
            if(nums[i]>target)  break;  // no need to explore
            temp.push_back(nums[i]);
            solve(i+1,target-nums[i],nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(begin(candidates),end(candidates));
        solve(0,target,candidates);
        return ans;
    }
};