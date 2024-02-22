class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> trustCount(n+1,{0,0});    // first is incoming and second is outgoing
        for(auto x:trust){
            trustCount[x[0]].second++;
            trustCount[x[1]].first++;
        }
        for(int i = 1;i<=n;i++){
            if(trustCount[i].first==n-1 && trustCount[i].second==0) return i;
        }
        return -1;
    }
};