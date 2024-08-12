class Solution {
    int n;
    vector<vector<int>> dp; // Memoization table

    int solve(int l, int h, string &s) {
        if (l > h) return 0;
        if (l == h) return 1;

        if (dp[l][h] != -1) return dp[l][h];

        int idx = l + 1;
        while (idx <= h && s[idx] == s[l]) idx++;
        int result = 1 + solve(idx, h, s);

        for (int j = idx; j <= h; j++) {
            if (s[j] == s[l]) {
                result = min(result, solve(idx, j - 1, s) + solve(j, h, s));
            }
        }

        return dp[l][h] = result;
    }

public:
    int strangePrinter(string s) {
        n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};
