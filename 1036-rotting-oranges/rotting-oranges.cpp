class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;       // {row, col}, time
        int m = grid.size();
        int n = grid[0].size();
        
        bool vis[m][n];
        memset(vis, false, sizeof(vis)); // Initialize vis array
        
        // Push rotten oranges into the queue and mark them as visited
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        
        int tm = 0;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();
            
            int delRows[] = {-1, 0, 1, 0};
            int delCols[] = {0, -1, 0, 1};
            
            // Explore neighboring cells
            for(int i = 0; i < 4; i++) {
                int nRow = r + delRows[i];
                int nCol = c + delCols[i];
                
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = true; // Mark as visited
                }
            }
        }
        
        // Check for unrotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == 1)    return -1;
            }
        }
        
        return tm;
    }
};
