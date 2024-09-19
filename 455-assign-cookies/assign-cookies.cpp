class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();
        int prev = 0;
        int content = 0;
        for (int i = 0; i < n; i++) {
            int gf = g[i]; 

            // Use binary search to find the smallest cookie >= gf
            prev = lower_bound(s.begin() + prev, s.end(), gf) - s.begin();

            if (prev < m) {
                content++;
                prev++;     
            } else {
                break;  // If no more cookies left to satisfy any child, stop
            }
        }

        return content;
    }
};