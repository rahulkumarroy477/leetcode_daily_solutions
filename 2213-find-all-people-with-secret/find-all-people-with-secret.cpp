class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        
        //constructing graph
        
        for(auto it:meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        // store key
        vector<bool> hasKey(n,false);
        
        // priority queue on the basis of time
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});
        q.push({0,firstPerson});
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            // if(hasKey[it.second])   continue;
            hasKey[it.second] = true;
            for(auto node:adj[it.second]){
                int p = node.first;
                int tm = node.second;
                
                if(tm>=it.first and !hasKey[p]){
                    q.push({tm,p});
                }
            }
        }
        
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(hasKey[i])   ans.push_back(i);
        }
        return ans;
    }
};
