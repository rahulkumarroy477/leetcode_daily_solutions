class Solution {
    typedef pair<int,pair<int,int>> P;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<pair<int,int>> directions{{0,-1},{-1,0},{0,1},{1,0}};
        // dijkstra algorithm
        priority_queue<P,vector<P>, greater<P>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;
        int ans = INT_MAX;
        while(!pq.empty()){

            auto top = pq.top();
            int t = top.first;
            int i = top.second.first;
            int j = top.second.second;
            pq.pop();
            if(i==n-1 && j==n-1){
                return t;
            }

            for(auto &[dx,dy]:directions){
                int ni = i + dx;
                int nj = j + dy;
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    vis[ni][nj] = true;
                    pq.push({max(t, grid[ni][nj]), {ni, nj}});
                }
            }
        }

        return -1;
    }
};