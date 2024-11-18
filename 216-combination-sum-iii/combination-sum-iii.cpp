class Solution {
public:
    vector<int> nums, temp;
    vector<vector<int>> ans;

    void solve(int idx, int k, int target){

        if(target < 0 || idx > 9)  return;
        if(target == 0){
            if(temp.size() == k){
                ans.push_back(temp);
            }
            return;
        }
        // take
        if(nums[idx] <= target){
            temp.push_back(nums[idx]);
            solve(idx+1, k, target-nums[idx]);
            temp.pop_back();
        }
        solve(idx+1, k, target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        for(int i = 1; i<=9; i++){
            nums.push_back(i);
        }
        solve(0,k,n);
        return ans;
    }
};