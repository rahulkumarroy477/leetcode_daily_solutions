class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        multiset<int> st;
        for(int i = 0;i<k;i++){
            st.insert(nums[i]);
        }
        ans.push_back(*st.rbegin());
        for(int i = k;i<n; i++){
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            ans.push_back(*st.rbegin());
        }

        return ans;
    }
};