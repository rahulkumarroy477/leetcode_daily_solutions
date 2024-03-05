class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i<j and s[i]==s[j]){
            char ch = s[i];
            while(i<n and s[i]==ch) i++;
            while(j>=i and s[j]==ch)    j--;
        }
        return j-i+1;
    }
};