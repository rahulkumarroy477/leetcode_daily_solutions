class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1;
        int n = nums.size();
        
        vector<int> suffix(n,1);
        for(int i = n-2;i>=0;i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }
        
        int temp;
        for(int i = 0;i<n;i++){
            temp = nums[i];
            nums[i] = product * suffix[i];
            product = product * temp;
        }
        
        return nums;
    }
};