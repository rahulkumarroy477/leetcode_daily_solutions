class Solution {
public:
    string compressedString(string word) {
        string ans = "";

        int n = word.length();
        for(int i = 0;i<n;i++){
            int j = i+1;
            while(j<n and word[j] == word[i] and j-i < 9)   j++;
            ans += to_string(j-i);
            ans.push_back(word[i]);
            i = j-1;
        }

        return ans;
    }
};