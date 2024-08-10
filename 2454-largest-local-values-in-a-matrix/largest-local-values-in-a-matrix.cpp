class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> t(n-2,vector<int>(n-2,1));
        for(int i = 0;i<n-2;i++){
            for(int j = 0;j<n-2;j++){
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        t[i][j] = max(t[i][j], grid[i+k][j+l]);
                    }
                }
            }
        }

        return t;

    }
};