class Solution {
vector<vector<string>>ans;
bool isPalindrome(string s){
    int n=s.size();
    int i=0;
    int j=n-1;
    while(i<=j){
        if(s[i]!=s[j])
            return false;
            i++;
            j--;
    }
    return true;
}
void solve(int i,int n,string &s,vector<string>helper){
    if(i==n){
        ans.push_back(helper);
        return;
    }
    string str="";
    for(int k=i;k<n;k++){
        str.push_back(s[k]);
        if(isPalindrome(str)){
            helper.push_back(str);
            solve(k+1,n,s,helper);
            helper.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>helper;
        solve(0,n,s,helper);
        return ans;
    }
};