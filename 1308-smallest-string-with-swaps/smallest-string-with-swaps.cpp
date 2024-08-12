class Solution {
    vector<int> parent;
    vector<int> rank;

    int findP(int child){
        if(parent[child]==child)    return child;
        return parent[child] = findP(parent[child]);
    }

    void Union(int x, int y){
        int pX = findP(x);
        int pY = findP(y);

        if(pX==pY)  return;

        if(rank[pX]>rank[pY]){
            parent[pY] = pX;
        }
        else if(rank[pY]>rank[pX]){
            parent[pX] = pY;
        }
        else{
            parent[pY] = pX;
            rank[pX]++;
        }
    }

public:

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        rank.resize(n,1);
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(const auto &pair:pairs){
            Union(pair[0],pair[1]);
        }

        unordered_map<int,priority_queue<char,
        vector<char>, greater<char>>> mp;

        // for(int x:parent)   cout<<x<<" ";
        for(int i = 0;i<n;i++){
            int root = findP(i);
            mp[root].push(s[i]);
        }
        string ans = "";
        for(int i = 0;i<n;i++){
            ans.push_back(mp[parent[i]].top());
            mp[parent[i]].pop();
        }
        return ans;
    }
};