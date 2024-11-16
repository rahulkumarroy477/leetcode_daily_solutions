class Solution {
typedef pair<int,int> P;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // construct graph
        vector<P> adj[n+1];
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        
        priority_queue<P, vector<P>, greater<P>> minH;
        dist[k] = 0;
        minH.push({0,k});

        while(!minH.empty()){
            auto [cost, node] = minH.top();
            minH.pop();

            for(auto [child, wt] : adj[node]){
                if(cost + wt < dist[child]){
                    dist[child] = cost + wt;
                    minH.push({dist[child],child});
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i] == INT_MAX)  return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};