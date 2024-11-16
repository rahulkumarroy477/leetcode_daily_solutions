class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using floyd warshall

        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i = 0;i<n;i++)  dist[i][i] = 0;

        for(int k = 0; k<n; k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};