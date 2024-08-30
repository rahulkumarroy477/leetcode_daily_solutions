class Solution {
    vector<int> dp;
    vector<vector<int>> prefixFreq;

    bool ok(int i, int j, string &s) {
        int freq = prefixFreq[j][s[i] - 'a'] - (i > 0 ? prefixFreq[i - 1][s[i] - 'a'] : 0);

        for (int k = 0; k < 26; k++) {
            int temp = prefixFreq[j][k] - (i > 0 ? prefixFreq[i - 1][k] : 0);
            if (temp != 0 && temp != freq) {
                return false;
            }
        }
        return true;
    }

    int solve(int i, string &s) {
        int n = s.length();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (ok(i, j, s)) {
                int cost = 1 + solve(j + 1, s);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    void fillPrefixFreq(const string &s) {
        int n = s.length();
        prefixFreq.assign(n, vector<int>(26, 0));

        vector<int> temp(26, 0);
        for (int i = 0; i < n; i++) {
            temp[s[i] - 'a']++;
            prefixFreq[i] = temp;  // Store the current state of temp in prefixFreq
        }
    }

public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        dp.resize(n, -1);
        fillPrefixFreq(s);
        return solve(0, s);
    }
};
