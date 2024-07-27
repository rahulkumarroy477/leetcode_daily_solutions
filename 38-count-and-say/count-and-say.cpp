class Solution {
string rle(string s){
    string ans;
    int n = s.length();
    int i = 0, j = 0;

    while(j<n){
        while(j<n && s[i]==s[j]){
            j++;
        }
        ans.append(to_string(j-i));
        ans.push_back(s[i]);
        i=j;
    }

    return ans;
}
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        return rle(countAndSay(n-1));
    }
};