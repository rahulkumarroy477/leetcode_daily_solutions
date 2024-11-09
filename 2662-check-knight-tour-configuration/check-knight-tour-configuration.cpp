class Solution {
private:
    int m, n;
    vector<pair<int,int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    bool ok(int r, int c){
        return (r>=0 and r<m and c>=0 and c<n);
    }
public:
    bool dfs(int r, int c,int count, vector<vector<int>>& grid){
        if(count == m*n - 1) return true;

        for(auto [dr,dc]: dir){
            int nr = r + dr;
            int nc = c + dc;

            if(ok(nr,nc) and grid[nr][nc] == count + 1){
                if(dfs(nr,nc,count+1, grid) == true)    return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {

        if(grid[0][0] != 0) return false;
        m = grid.size();
        n = grid[0].size();

        return dfs(0,0,0,grid);
    }
};