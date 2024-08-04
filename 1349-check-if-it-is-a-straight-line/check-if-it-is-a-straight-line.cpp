class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        int n = coords.size();
        int x0 = coords[0][0], y0 = coords[0][1];
        int dx = coords[1][0]-x0;
        int dy = coords[1][1]-y0;

        // cout<<slope<<endl;

        for(int i = 2;i<n;i++){
            int x = coords[i][0];
            int y = coords[i][1];

            if(dy*(x-x0)!=dx*(y-y0))    return false;
        }
        return true;
    }
};