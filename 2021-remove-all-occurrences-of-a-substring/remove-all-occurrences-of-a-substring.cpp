class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = s.length();
        int n = part.length();
        for(char ch:s){
            st.push(ch);

            if(st.size()>=n){
                string temp = "";
                for(int i = 0;i<n;i++){
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(),temp.end());

                if(temp != part){
                    for(char c:temp){
                        st.push(c);
                    }
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};