class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> dist(m,vector<int>(n,0));

        queue<vector<int>> q;
        // insert all 0s
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }

        // iterate over queue
        vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0}};

        while(!q.empty()){
            vector<int> front = q.front();
            q.pop();
            int x = front[0];
            int y = front[1];
            int steps = front[2];
            dist[x][y] = steps;

            
            for(auto &[dx,dy]:dir){
                int nx = x + dx;
                int ny = y + dy;

                if(nx>=0 && nx<m && ny>=0 && ny<n && 
                !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({nx,ny,steps+1});
                }
            }
        }

        return dist;
    }
};