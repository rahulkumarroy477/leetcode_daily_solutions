class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for(string log:logs){
            if(!st.empty() and log == "../"){
                st.pop();
            }
            else if(log == "./")    continue;
            else {
                if(log == "../")    continue;
                log.pop_back();
                st.push(log);
            }
        }
        int count = st.size();
        while(!st.empty()){
            cout<<st.top()<<endl;
            st.pop();
        }
        return count;
    }
};