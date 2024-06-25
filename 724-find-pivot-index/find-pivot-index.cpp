class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 1;i<n;i++){
            nums[i] += nums[i-1];
        }
        int prev = 0;
        for(int i = 0;i<n;i++){
            int nextSum = nums[n-1] - nums[i];
            if(prev == nextSum) return i;
            prev = nums[i];
        }
        return -1;
    }
};