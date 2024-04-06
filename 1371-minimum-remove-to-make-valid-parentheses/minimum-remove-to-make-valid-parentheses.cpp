class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        unordered_set<int> remove_idx;
        
        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty())  
                    remove_idx.insert(i);
                else
                    st.pop();   
            }
        }
        
        // only '(((' these are present
        
        while(!st.empty()){
            remove_idx.insert(st.top());
            st.pop();
        }
        string ans;
        
        for(int i = 0;i<n;i++){
            if(remove_idx.find(i)!=remove_idx.end())    continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};