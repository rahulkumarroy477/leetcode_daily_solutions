class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // calculate the length of the string
        int n = s.length();
        long long len = 0;
        for(char ch:s){
            if(isdigit(ch))
                len *= ch - '0';
            else len++;
        }
        cout<<len<<endl;

        for(int i = n-1;i>=0;i--){
            char ch = s[i];
            k %= len;
            if(k==0 && isalpha(ch)) return string(1,ch);
            if(isdigit(ch)) len /= ch-'0';
            else len--;
        }

        return "";
    }
};