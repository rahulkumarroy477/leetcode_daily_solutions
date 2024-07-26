class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();
        int prev = 0;
        int content = 0;
        for(int i = 0;i<n;i++){
            int gf = g[i];

            while(prev<m && s[prev]<gf)    prev++;
            if(prev == m)   break;
            content++;
            prev++;
        }

        return content;
    }
};