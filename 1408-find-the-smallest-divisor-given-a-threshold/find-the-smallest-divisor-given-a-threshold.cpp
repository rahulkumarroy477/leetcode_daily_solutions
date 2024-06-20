class Solution {
public:
    int solve(vector<int> &nums, int divisor){
        int sum = 0;
        for(auto x:nums){
            sum += (x + divisor - 1) / divisor; // Ceiling division
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;
        while (start <= end) {
            int divisor = start + (end - start) / 2;

            int summation = solve(nums, divisor);
            if (summation <= threshold) {
                ans = divisor;
                end = divisor - 1;
            } else {
                start = divisor + 1;
            }
        }

        return ans;
    }
};