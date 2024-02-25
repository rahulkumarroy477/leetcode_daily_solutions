class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        // mutlisource bfs
        queue<pair<int,int>> q;
        // insert all boundary 1's
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if((i==0 or i==m-1 or j==0 or j==n-1) and grid[i][j]==1){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i =0;i<4;i++){
                int r = row + delRow[i];
                int c = col + delCol[i];
                
                if(r>=0 and r<m and c>=0 and c<n and vis[r][c]==0 and grid[r][c]==1){
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
            
        }
        
        // get all unvisited cells
        
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==0 and grid[i][j]==1)  count++;
            }
        }
        return count;
    }
};