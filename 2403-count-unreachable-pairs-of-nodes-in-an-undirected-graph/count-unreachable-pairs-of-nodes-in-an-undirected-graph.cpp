class Solution {
    private:
        vector<int> parent;
        vector<int> rank;
        int find(int a){
            if(parent[a]==a)
                return a;
            return parent[a] = find(parent[a]);
        }

        void Union(int a, int b){
            int pA = find(a);
            int pB = find(b);

            if(pA == pB)    return;

            if(rank[pA]>rank[pB]){
                parent[pB] = pA;
            }
            else if(rank[pA]<rank[pB]){
                parent[pA] = pB;
            }
            else {
                parent[pB] = pA;
                rank[pA]++;
            }
        }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;

        rank.resize(n,0);
        parent.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            Union(u,v);
        }
        unordered_map<int,int> mp;      // parent, size
        for(int i = 0;i<n;i++){
            mp[find(i)]++;
        }
        for(auto it:mp)
            cout<<it.first<<" "<<it.second<<endl;

        long long remNodes = n;
        for(auto it:mp){
            long long size = it.second;
            ans += size*(remNodes-size);

            remNodes -= size;
        }

        return ans;

    }
};