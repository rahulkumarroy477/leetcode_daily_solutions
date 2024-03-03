class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int n = s.length();
        for(int i =0;i<n;i++){
            char ch  = s[i];
            if((ch>='a' and ch<='z') or (ch>='0' and ch<='9')){
                temp.push_back(ch);
            }
            else if(ch>='A' and ch<='Z'){
                temp.push_back(ch + 'a' - 'A');
            }
             
        }
        string rev = temp;
        reverse(temp.begin(),temp.end());
        if(rev == temp) return true;
        return false;
    }
};