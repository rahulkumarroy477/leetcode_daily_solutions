class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;

        for(char ch:s){
            if(ch == ')'){
                string temp = "";
                while(st.top()!=string(1,'(')){
                    temp.append(st.top());
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                st.push(temp);
                cout<<temp<<endl;
            }
            else st.push(string(1,ch));
        }
        string ans = "";
        while(!st.empty()){
            ans.append(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};