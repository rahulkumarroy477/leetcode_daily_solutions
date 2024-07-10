class Solution {


public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // construct the graph
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        // perform bfs
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            for(auto &child:adj[node]){
                auto [childNode,T] = child;
                if(t + T < time[childNode]){
                    time[childNode] = t+T;
                    pq.push({t+T,childNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            ans = max(ans,time[i]);
        }

        return ans==INT_MAX?-1:ans;
    }
};