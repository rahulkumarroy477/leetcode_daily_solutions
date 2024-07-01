class Solution {
    private:
    void assignAncestor(int u,int curr,vector<int> adj[],vector<vector<int>> &ancestors){
        for(int &v:adj[curr]){
            if(ancestors[v].empty() || ancestors[v].back()!=u){
                ancestors[v].push_back(u);
                assignAncestor(u,v,adj,ancestors);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);

        vector<int> adj[n];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for(int i = 0;i<n;i++){
            assignAncestor(i,i,adj,ancestors);
        }

        return ancestors;

    }
};