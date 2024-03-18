class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        int ans = 1;
        int i = 0, j = 1;
        
        int n = points.size();
        while(j<n){
            int cs = points[i][0], ce = points[i][1];
            int ns = points[j][0], ne = points[j][1];
            if(ns>ce)   {
                ans++;
                i = j;
                j++;
            }
            else if(ce<=ne){
                j++;
            }
            else if(ce>ne){
                i = j;
                j++;
            }
        }
        return ans;
    }
};