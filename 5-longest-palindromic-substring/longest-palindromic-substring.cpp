class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        vector<vector<bool>> pal(n,vector<bool>(n,false));

        int idx = 0, maxLen = 1;
        for(int i = 0;i<n;i++)
            pal[i][i] = true;
        
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                pal[i][i+1] = true;
                idx = i, maxLen = 2;
            }
        }

        for(int length = 3; length<=n;length++){
            for(int i = 0;i<=n-length;i++){
                int j = i + length - 1;
                if(s[i] == s[j] && pal[i+1][j-1]){
                    pal[i][j] = true;
                    idx = i, maxLen = length;
                }
            }
        }

        return s.substr(idx,maxLen);


        
    }
};