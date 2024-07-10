class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // normal bfs as only one path exists

        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1)    return -1;
        vector<vector<int>> directions{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int level = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto [x,y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1)    return level + 1;
                for(const auto &dir: directions)
                {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0){
                        grid[newX][newY] = 1;
                        q.push({newX,newY});
                    }
                }
                
            }
            level++;
        }

        return -1;
    }
};