class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char> st;
        int open = 0;
        int ans = 0;
        for(char ch:s){
            if(ch=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }

        ans += open;
        return ans;

    }
};