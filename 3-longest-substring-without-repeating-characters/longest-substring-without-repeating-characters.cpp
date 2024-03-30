class Solution {
public:
    int lengthOfLongestSubstring(string s)  {
        int n = s.length();
        
        unordered_set<char> mp;
        
        int i = 0, j = 0;
        int count = 0;
        
        while(j<n){
            // unique character no repeating
            char ch = s[j];
            if(mp.find(ch)!=mp.end())
            {
                while(s[i]!=ch){
                    mp.erase(s[i]);
                    i++;
                }
                i++;
                
            }
                
            else{
                mp.insert(ch);
                count = max(count,j-i+1);
            }
            j++;
            
        }
        return count;
        
        
    }
};