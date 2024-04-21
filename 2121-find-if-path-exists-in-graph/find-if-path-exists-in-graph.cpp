class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // construct graph
        if(n==1)    return true;
        
        vector<bool> vis(n,false);
        vis[source] = true;
        
        bool flag = true;
        
        while(flag){
            flag = false;
            
            for(const auto &edge:edges){
                if(vis[edge[0]]!=vis[edge[1]]){
                    vis[edge[0]] = vis[edge[1]] = flag = true;
                }
            }
            
            if(vis[destination])    return true;
        }
        
        return false;
    }
};