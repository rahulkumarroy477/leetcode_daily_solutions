class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size();
        int n = s.size();
        int count = 0;
        int i = 0, j = 0;
        
        while(i<m and j<n){
            while(j<n){
                if(s[j]>=g[i]){
                    count++;
                    break;
                }
                j++;
            }
            j++;
            i++;
            if(j==n)    break;
                
        }
        return count;

    }
};