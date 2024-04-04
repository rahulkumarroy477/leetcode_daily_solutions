class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch=='('){
                count++;
                ans = max(ans,count);
            }
            else if(ch==')'){
                count--;
            }
        }
        return ans;
    }
};