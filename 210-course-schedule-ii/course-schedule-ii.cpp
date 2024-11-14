class Solution {
public:

    bool dfs(int node,vector<bool> &inPath,vector<bool> &vis, vector<int> &st, vector<int> adj[]){
        vis[node] = true;
        inPath[node] = true;
        for(int child: adj[node]){
            if(!vis[child]){
                if(dfs(child,inPath,vis,st,adj) == true)   return true; 
            }
            else if(inPath[child])   return true;
        }

        st.push_back(node);
        inPath[node] = false;
        return false;
    }

    vector<int> topoSort(int n, vector<int> adj[]){
        vector<int> st;
        vector<bool> vis(n,false);
        vector<bool> inPath(n,false);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,inPath,vis,st,adj))
                    return {};
            }
        }

        reverse(st.begin(),st.end());
        return st;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // construct the graph

        vector<int> adj[numCourses];

        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];

            // v --> u
            adj[v].push_back(u);
        }

        return topoSort(numCourses,adj);
    }
};