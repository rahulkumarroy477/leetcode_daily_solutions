class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        int prevprev = 0;
        int prev = nums[0];
        // case1
        for(int i = 2;i<n;i++){
            int take = nums[i-1] + prevprev;
            int skip = prev;

            prevprev = prev;
            prev = max(take,skip);
        }
        int case1 = prev;
        prevprev = 0; 
        prev = nums[1];

        // case2
        for(int i = 3;i<=n;i++){
            int take = nums[i-1] + prevprev;
            int skip = prev;

            prevprev = prev;
            prev = max(take,skip);
        }

        return max(prev,case1);
    }
};