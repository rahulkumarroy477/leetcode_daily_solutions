class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n];
        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            // converting to 0 based indexing
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>> > pq;

        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        pq.push({0,0});
        dist1[0] = 0;
        
        while(!pq.empty()){

            auto [timeElapsed, node] = pq.top();
            pq.pop();

            if(node == n-1 && dist2[n-1]!=INT_MAX)
                return dist2[n-1];
            
            int div = timeElapsed/change;
            // red signal
            if(div%2==1){
                // time after which it allowed to move
                timeElapsed = change*(div + 1); 
            }

            for(auto &child:adj[node]){
                if(dist1[child] > timeElapsed + time){
                    dist2[child] = dist1[child];
                    dist1[child] = timeElapsed + time;
                    pq.push({dist1[child],child});
                }
                else if(dist2[child]>timeElapsed+time &&
                dist1[child]!=timeElapsed+time){
                    dist2[child] = timeElapsed + time;
                    pq.push({dist2[child],child});
                }
            }
        }

        return -1;
    }
};