class Solution {
bool palindrome[2001][2001];
int t[2001][2001];
void fillPalindrome(string &s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            palindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            palindrome[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                palindrome[i][j] = (s[i] == s[j] && palindrome[i + 1][j - 1]);
                // Check for longer palindromes
            }
        }
    }
bool check(int i, int j, string &s){
    while(i<=j){
        if(s[i]!=s[j])  return false;
        i++, j--;
    }

    return true;
}
int solve(int i, int j, string &s){
    if(i>=j)    return 0;
    // if(check(i,j,s))    return 0;
    if(palindrome[i][j])    return 0;
    if(t[i][j]!=-1) return t[i][j];
    int mini = 1e9;
    for(int k = i;k<j;k++){
        if (palindrome[i][k]) {
            int temp = 1 + solve(k + 1, j, s);
            mini = min(mini, temp);
        }
    }

    return t[i][j] = mini;
}
public:
    int minCut(string s) {

        fillPalindrome(s);
        memset(t,-1,sizeof(t));
        return solve(0,s.length()-1,s);
    }
};