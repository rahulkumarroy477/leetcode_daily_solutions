class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) // If k is less than or equal to 1, no subarray can have a product less than k
            return 0;
        
        long long product = 1;
        int count = 0;
        int n = nums.size();
        int i = 0, j = 0;
        
        while (j < n) {
            product *= nums[j++];
            
            // Shrink the window from the left until the product is less than k
            while (product >= k) {
                product /= nums[i++];
            }
            
            // Increment count by the size of the current window
            count += j - i;
        }
        
        return count;
    }
};
