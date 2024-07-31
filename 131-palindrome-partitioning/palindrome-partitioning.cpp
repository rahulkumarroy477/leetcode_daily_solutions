class Solution {
bool palindrome[17][17];
vector<vector<string>> ans;
vector<string> temp;
void setPalindrome(string &s){

    int n = s.length();
    // one length
    for(int i = 0;i<n;i++){
        palindrome[i][i] = true;
    }
    // two length
    for(int i = 0;i<n-1;i++){
        if(s[i]==s[i+1])
            palindrome[i][i+1] = true;
    }

    for(int length = 3;length<=n;length++){
        for(int i = 0;i<=n-length;i++){
            int j = i + length - 1;
            if(s[i]==s[j] && palindrome[i+1][j-1])
                palindrome[i][j] = true;
        }
    }
}

void solve(int i, string &s){
    if(i == s.length()){
        ans.push_back(temp);
        return;
    }
    for(int j = i;j<s.length();j++){
        if(palindrome[i][j]){
            temp.push_back(s.substr(i,j-i+1));
            solve(j+1,s);
            temp.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        setPalindrome(s);
        solve(0,s);
        return ans;
    }
};