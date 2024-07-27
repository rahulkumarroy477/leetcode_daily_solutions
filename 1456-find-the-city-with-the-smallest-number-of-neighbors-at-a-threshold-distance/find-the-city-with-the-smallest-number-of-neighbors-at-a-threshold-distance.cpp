class Solution {

int dijkstra(vector<pair<int,int>> adj[],int n,int src, int distanceThreshold){
    vector<int> dist(n,1e9);
    dist[src] = 0;
    set<pair<int,int>> st;
    st.insert({0,src});

    while(!st.empty()){
        auto &it = *st.begin();
        int wt = it.first;
        int node = it.second;
        st.erase(it);
        for(auto &child:adj[node]){
            int adjNode = child.first;
            int W = child.second;

            if(wt + W<dist[adjNode]){
                if(dist[adjNode]!=1e9){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = wt + W;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    // get all nodes within threshold distance
    int count = 0;
    for(const int &x:dist){
        if(x!=1e9 and x<=distanceThreshold)    count++;
    }
    return count;

}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // adjacency list
        vector<pair<int,int>> adj[n];
        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        // no negative edge weights--> we can use dijkstra algorithm here
        int idx = -1;
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int d = dijkstra(adj,n,i,distanceThreshold);
            if(d<=ans){
                ans = d;
                idx = i;
            }
        }
        return idx;
    }
};