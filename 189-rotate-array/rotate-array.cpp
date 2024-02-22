class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // using extra space
        
        int n = nums.size();
        
        vector<int> copy_nums(n,0);
        for(int i = 0;i<n;i++)  copy_nums[(i+k)%n] = nums[i];
        for(int i = 0;i<n;i++)  nums[i] = copy_nums[i];
    }
};