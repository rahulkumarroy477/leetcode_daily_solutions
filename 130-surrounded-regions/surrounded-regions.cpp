class Solution {
private:
    int m, n;
    vector<vector<bool>> vis;

    bool ok(int i, int j){
        return (i>=0 && i<m && j>=0 && j<n && !vis[i][j]);
    }

    vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int x, int y,vector<vector<char>>&board){
        vis[x][y] = true;

        for(auto [dx,dy]:dir){
            int nx = x + dx;
            int ny = y + dy;

            if(ok(nx,ny) && board[nx][ny]=='O'){
                dfs(nx,ny,board);
            }
        }
        cout<<"dfs called"<<endl;

    }
public:


    void solve(vector<vector<char>>& board) {
        // boundary traversal
        m = board.size();
        n = board[0].size();
        vis.resize(m,vector<bool>(n,false));

        // boundary traversal

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || 
                j == n-1)  && board[i][j] == 'O' && !vis[i][j]){
                    dfs(i,j,board);
                }
            }
        }

        // mark remaining O with X

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }



    }
};