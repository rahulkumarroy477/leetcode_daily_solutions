class Solution {
    // vector<vector<bool>> vis;
    vector<vector<int>> graph;
    int M , N;
    vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int i, int j){
        graph[i][j] = 1;

        for(auto &[dx,dy]:dir){
            int ni = i + dx;
            int nj = j + dy;

            if(ni>=0 && ni<M && nj>=0 && nj<N && graph[ni][nj]==0){
                dfs(ni,nj);
            }
        }
    }

    void printGraph(){
        for(auto x:graph){
            for(int y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].length();
        M = 3*m, N = 3*n;
        graph.resize(M,vector<int>(N,0));

        // replace / with 0 0 1 ,  replace \ with 1 0 0
        //                0 1 0                   0 1 0
        //                1 0 0                   0 0 1

        // fill the graph matrix
        int i = 0;
        for(string s:grid){
            int j = 0;
            for(const char &ch:s){
                if(ch == '/'){
                    graph[i][j+2] = 1;
                    graph[i+1][j+1] = 1;
                    graph[i+2][j] = 1;
                }
                else if(ch == '\\'){
                    graph[i][j] = 1;
                    graph[i+1][j+1] = 1;
                    graph[i+2][j+2] = 1;
                }
                j+=3;
            }
            i+=3;
        }
        

        int count = 0;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(graph[i][j]==0){
                    // call for dfs
                    // printGraph();
                    dfs(i,j);
                    count++;
                    // cout<<count<<endl;
                }
            }
        }

        return count;

    }
};