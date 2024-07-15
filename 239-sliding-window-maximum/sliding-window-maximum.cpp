class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st;
        int i = 0;
        while(i<k){
            st.insert(nums[i]);
            i++;
        }
        vector<int> ans;
        ans.push_back(*st.rbegin());
        while(i<n){
            st.insert(nums[i]);
            st.erase(st.find(nums[i-k]));

            ans.push_back(*st.rbegin());
            i++;
        }

        return ans;
    }
};