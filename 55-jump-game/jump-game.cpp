class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(maxDist < i) return false;

            maxDist = max(maxDist, i + nums[i]);
            if(maxDist >= n-1)  return true;
        }

        return false;
    }
};