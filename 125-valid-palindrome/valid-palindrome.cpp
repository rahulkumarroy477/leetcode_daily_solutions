class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char ch: s){
            if(isalnum(ch)){
                if(ch>='A' and ch <= 'Z'){
                    str.push_back('a' + ch-'A');
                }else str.push_back(ch);
            }
        }

        cout<<str<<endl;

        int n = str.length();
        for(int i = 0;i<n/2;i++){
            if(str[i] != str[n-i-1])
                return false;
        }

        return true;
    }
};