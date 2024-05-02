class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = 0;
        
        unordered_set<int> mp;
        for(const auto &x:nums){
            if(mp.count(x))    ans = max(ans,abs(x));
            else mp.insert(-x);
        }
        return ans==0?-1:ans;
    }
};