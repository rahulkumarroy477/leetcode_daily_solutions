class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         using summation
        int n = nums.size();
        // long long sum = n*(n+1)/2;
        // for(int i = 0;i<nums.size();i++){
        //     sum-=nums[i];
        // }
        // return sum;
        
//         xor method
        int ans = n;
        for(int i = 0;i<n;i++){
            ans = ans^i;
            ans = ans^nums[i];
        }
        return ans;
    }
};