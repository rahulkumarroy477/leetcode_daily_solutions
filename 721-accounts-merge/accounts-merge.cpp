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

        if(pA==pB)  return;

        if(rank[pA]>rank[pB]){
            parent[pB] = pA;
        }
        else if(rank[pA]<rank[pB]){
            parent[pA] = pB;
        }
        else{
            parent[pB] = pA;
            rank[pA]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0;i<n;i++)
            parent[i] = i;

        unordered_map<string,int> mp;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) != mp.end()){
                    Union(mp[mail],i);
                }
                else{
                    mp[mail] = i;
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it:mp){
            string mail = it.first;
            int node = find(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};