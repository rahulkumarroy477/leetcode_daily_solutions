class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // get the breakpoint

        int n = nums.size();
        int idx = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx == -1)   {
            reverse(nums.begin(),nums.end());
            return;
        }

        int j = n - 1;
        while (nums[j] <= nums[idx]) {
            --j;
        }

        swap(nums[idx],nums[j]);
        reverse(nums.begin()+idx+1,nums.end());
    }
};