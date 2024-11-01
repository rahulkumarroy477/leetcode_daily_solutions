class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        unordered_set<int> st(target.begin(),target.end());

        for(int i = 1;i<=target.back();i++){
            ans.push_back("Push");
            if(st.find(i) == st.end())  ans.push_back("Pop");
        }
        return ans;
    }
};