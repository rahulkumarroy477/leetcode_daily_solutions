class Solution {
    bool isPalindrome(string s){
        int n = s.length();
        for(int i =0;i<n/2;i++){
            if(s[i]!=s[n-i-1])  return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string word:words){
            if(isPalindrome(word))  return word;
        }
        return "";
    }
};