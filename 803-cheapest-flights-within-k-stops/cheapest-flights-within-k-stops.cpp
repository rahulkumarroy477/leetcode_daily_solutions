class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});      // k ,  node ,  dist
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.second.first;
            int cost = it.second.second;
            int stops = it.first;
            
            q.pop();
            
            if(stops>K) break;   // break
            for(auto iter:adj[node]){
                int adjNode = iter.first;
                int edge = iter.second;
                
                if(cost + edge < dist[adjNode]){
                    dist[adjNode] = cost + edge;
                    q.push({stops+1,{adjNode,cost+edge}});
                }
            }
        }
        if(dist[dst]==1e9)  return -1;
        return dist[dst];
    }
};
