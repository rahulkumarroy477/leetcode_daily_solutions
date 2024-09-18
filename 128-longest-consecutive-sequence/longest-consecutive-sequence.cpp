class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 1;

        for(int x: nums){
            // x is the starting number
            if(st.find(x-1)==st.end()){
                int cnt = 1;
                int startNum = x;

                while(st.find(startNum+1)!=st.end()){
                    cnt++;
                    startNum++;
                }

                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};