class Solution {

typedef pair<int,int> P;
private:
    int dijkstra(int source, int n, vector<P> adj[], int thresh){
        
        vector<int> dist(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> minH;
        dist[source] = 0;
        minH.push({0,source});

        while(!minH.empty()){
            auto [cost,node] = minH.top();
            minH.pop();


            for(auto [child,wt]: adj[node]){
                if(wt == INT_MAX)   continue;
                if(cost + wt < dist[child]){
                    dist[child] = cost + wt;
                    minH.push({dist[child],child});
                }
            }
        }


        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt += dist[i]<=thresh ? 1: 0;
        }

        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        // using floyd warshall

        // vector<vector<int>> dist(n, vector<int>(n,INT_MAX));

        // for(auto edge: edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     int wt = edge[2];

        //     dist[u][v] = wt;
        //     dist[v][u] = wt;
        // }

        // for(int i = 0;i<n;i++)  dist[i][i] = 0;

        // for(int k = 0; k<n; k++){
        //     for(int i = 0;i<n;i++){
        //         for(int j = 0;j<n;j++){
        //             if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
        //                 continue;
        //             dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        //         }
        //     }
        // }

        // int cntCity = n;
        // int cityNo = -1;
        // for(int i = 0;i<n;i++){
        //     int cnt = 0;
        //     for(int j = 0; j<n; j++){
        //         if(dist[i][j] <= distanceThreshold)
        //             cnt++;
        //     }

        //     if(cnt <= cntCity){
        //         cntCity = cnt;
        //         cityNo = i;
        //     }
        // }
        // return cityNo;

        vector<P> adj[n];

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int cnt = n;
        int city = -1;
        for(int i = 0;i<n;i++){
            int dj = dijkstra(i,n,adj,thresh);
            if(cnt >= dj){
                cnt = dj;
                city = i;
            }
        }

        return city;
    }
};