class Solution {
private:
    vector<int> color;
    bool dfs(int node,int col,vector<vector<int>> &graph){
        color[node] = col;

        for(const int &child: graph[node]){
            if(color[child]==-1){
                if(dfs(child,1-col,graph)==false)   return false;
            }
            else if(color[child] == col)    return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n,-1);

        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph)==false)   return false;
            }
        }

        return true;
    }
};