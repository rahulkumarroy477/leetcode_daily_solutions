class Solution {
public:
    int n;
    int expandFromCen(string &s, int l, int r){
        while(l>=0 and r<n and s[l] == s[r]){
            l--;
            r++;
        }

        return r-l-1;
    }
    string longestPalindrome(string s) {
        // expand from center approach
        n = s.length();
        int maxLen = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            int len1 = expandFromCen(s,i,i); // odd length palindrome
            int len2 = expandFromCen(s,i,i+1); // even length palindrome

            int len = max(len1,len2);
            if(len > maxLen){
                maxLen = len;
                start = i - (len - 1)/2;
            }
        }

        return s.substr(start,maxLen);
    }
};