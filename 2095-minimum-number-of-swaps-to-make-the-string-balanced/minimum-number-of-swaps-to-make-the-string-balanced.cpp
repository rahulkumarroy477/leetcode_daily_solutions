class Solution {
public:
    int minSwaps(string s) {
        int mismatch = 0;
        stack<char> st;

        for(char ch:s){
            if(ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()) st.pop();
                else mismatch++;
            }
        }

        return (mismatch+1)/2;
    }
};