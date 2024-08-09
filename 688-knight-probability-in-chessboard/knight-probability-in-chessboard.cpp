class Solution {

    double t[26][26][101];
    vector<pair<int,int>> dir = 
    {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    double solve(int i, int j, int k,int n){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }
        if(k==0)    return 1;

        // call for 8 directions
        if(t[i][j][k] != -1.0)  return t[i][j][k];
        double ans = 0;
        for(const auto &[dx,dy]:dir){
            int new_i = i + dx;
            int new_j = j + dy;
            ans += solve(new_i,new_j,k-1,n);
        }

        return t[i][j][k] = ans/8.0;

    }
public:
    double knightProbability(int n, int k, int row, int column) {
        // 3 variables changing
        // memset(t,-1.0,sizeof(t));
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                for (int k = 0; k < 101; ++k)
                    t[i][j][k] = -1.0;
            }
        }

        return solve(row,column,k,n);
    }
};