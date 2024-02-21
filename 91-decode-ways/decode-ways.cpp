class Solution {
public:
    int solve(int idx, string& s, unordered_set<string>& mp, unordered_map<int, int>& memo) {
        if (idx == s.length()) {
            return 1;
        }
        
        // Check if the result for the current index is already computed
        if (memo.find(idx) != memo.end()) {
            return memo[idx];
        }
        
        int ways = 0;
        string temp;
        temp.push_back(s[idx]);
        if (mp.count(temp) == 1) {
            ways += solve(idx + 1, s, mp, memo);
            
            if (idx + 1 < s.length()) {
                temp.push_back(s[idx + 1]);
                if (mp.count(temp) == 1) {
                    ways += solve(idx + 2, s, mp, memo);
                }
            }
        }
        
        // Memoize the result for the current index
        memo[idx] = ways;
        
        return ways;
    }
    
    int numDecodings(string s) {
        unordered_set<string> mp = {
            "1","2","3","4","5","6","7","8","9","10",
            "11","12","13","14","15","16","17","18","19","20",
            "21","22","23","24","25","26"
        };
        
        unordered_map<int, int> memo;
        return solve(0, s, mp, memo);
    }
};
