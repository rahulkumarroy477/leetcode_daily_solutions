class Solution {
    // int n;
    // int t[101];
    // int solve(int idx,vector<int> &nums){
    //     if(idx>=n)  return 0;

    //     if(t[idx]!=-1)  return t[idx];
    //     // take
    //     int take = nums[idx] + solve(idx+2,nums);
    //     int nottake = solve(idx+1,nums);

    //     return t[idx] = max(take,nottake);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);

        int prevprev = 0;
        int prev = nums[0];
        for(int i = 1;i<n;i++){
            int take = nums[i] + prevprev;
            int skip = prev;

            prevprev = prev;
            prev = max(take,skip);

        }

        return prev;
    }
};