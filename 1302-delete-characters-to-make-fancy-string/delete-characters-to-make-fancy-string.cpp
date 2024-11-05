class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int count = 0;
        char prev = s[0];
        string ans =  "";
        for(int i = 0;i<n;i++){
            char curr = s[i];
            if(curr == prev)    count++;
            else{
                ans += string(min(count,2),prev);
                prev = curr;
                count = 1;
            }
        }
        ans += string(min(count,2),prev);
        return ans;
    }
};