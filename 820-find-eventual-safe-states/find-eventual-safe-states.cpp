class Solution {
public:
    vector<bool> vis,pathVis,safe;
    bool dfs(int node, vector<vector<int>>& graph){
        vis[node] = true;
        pathVis[node] = true;
        safe[node] = false; 
        for(auto child : graph[node]){
            if(!vis[child]){
                if(dfs(child,graph)){
                    // safe[child] = false;
                    return true;
                }
            }
            else if(pathVis[child])
                return true;
        }
        safe[node] = true;
        pathVis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vis.resize(n,false);
        pathVis.resize(n,false);
        safe.resize(n,false);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph);
            }
        }

        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(safe[i])    ans.push_back(i);
        }

        return ans;
    }
};