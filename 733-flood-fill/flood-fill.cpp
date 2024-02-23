class Solution {
public:
    // void dfs(vector<vector<int>>& image, int i, int j, int color,int val)
    // {
    //     int m = image.size();
    //     int n = image[0].size();
    //     if(i<0||j<0||i>=m||j>=n) return;
    //     if(image[i][j]==color||image[i][j]!=val) return;
    //     image[i][j]=color;
    //     dfs(image,i-1,j,color,val);
    //     dfs(image,i+1,j,color,val);
    //     dfs(image,i,j-1,color,val);
    //     dfs(image,i,j+1,color,val);
    // }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        // DFS Part
        
        // int val = image[sr][sc];
        // dfs(image,sr,sc,color,val);
        // return image;
        
        
        // BFS Part
        
        int m = image.size();
        int n = image[0].size();
        
        bool vis[m][n];
        memset(vis,false,sizeof(vis));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        int curCol = image[sr][sc];
        image[sr][sc] = color;
        
        
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            int delRows[] = {-1,0,1,0};
            int delCols[] = {0,-1,0,1};
            q.pop();
            for(int i = 0;i<4;i++){
                int nRow = r + delRows[i];
                int nCol = c + delCols[i];
                
                if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and !vis[nRow][nCol] and image[nRow][nCol]==curCol){
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = true;
                    image[nRow][nCol] = color;
                }
            }
            
        }
        
        return image;
    }
};