class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i]!=']'){
                st.push(string(1, s[i])); // convert char to string
            }
            else{
                string substr = "";
                while(st.top()!="["){
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();   // to remove '['
                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                int num = stoi(k);
                // Repeat the substring num times and push back to stack
                string repeatedSubstr = "";
                for (int j = 0; j < num; j++) {
                    repeatedSubstr += substr;
                }
                st.push(repeatedSubstr);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};