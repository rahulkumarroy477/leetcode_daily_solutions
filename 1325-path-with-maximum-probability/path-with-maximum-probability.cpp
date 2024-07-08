class Solution {
public:

    double dijkstra(int n,vector<pair<double,int>> adj[],int start, int end){
        vector<double> dist(n,0.0);
        dist[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            double p = top.first;
            int node = top.second;
            if(node == end){
                return p;
            }
            for(auto &adjNode:adj[node]){
                int child = adjNode.second;
                double prob = adjNode.first;
                if(prob * p > dist[child]){
                    dist[child] = prob * p;
                    pq.push({dist[child],child});
                }
            }
        }

        return 0.0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        // construct map
        vector<pair<double, int>> adj[n];
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({prob, v});
            adj[v].push_back({prob, u});
        }

        return dijkstra(n,adj,start_node,end_node);
    }
};