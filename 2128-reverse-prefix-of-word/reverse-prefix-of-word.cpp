class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int n = word.length();
        while(i<n and word[i]!=ch){
            i++;
        }
        
        // word not found
        if(i<n) {
            reverse(word.begin(),word.begin()+i+1);
        }
        return word;
    }
};