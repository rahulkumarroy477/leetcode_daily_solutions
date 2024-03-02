class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // xor method
        int ans = 0;
        for(const int &x:nums){
            ans = ans^x;
        }
        return ans;
    }
};