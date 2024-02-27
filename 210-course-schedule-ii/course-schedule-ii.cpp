class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // construct the graph
        
        vector<int> adj[n];
        for(auto task:prerequisites){
            int u = task[0];
            int v = task[1];
            adj[v].push_back(u);
        }
        
        
        // calculate indegree of all nodes;
        vector<int> indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        // insert all nodes with indegree 0
        
        for(int i =0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)    q.push(adjNode);
            }
        }
        
        if(topo.size()==n)  return topo;
        return {};
    }
};