class Solution {
public:
    int lengthOfLongestSubstring(string s)  {
        int n = s.length();
        if(n==0 or n==1)    return n;
        unordered_set<char> mp;
        int ans = 1;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(mp.count(s[i])) {
                ans = max(count,ans);
                while (mp.count(s[i])) {
                    mp.erase(s[i - count]);
                    count--;
                }
            }
            mp.insert(s[i]);
            count++;
        }
        return max(count,ans);
    }
};