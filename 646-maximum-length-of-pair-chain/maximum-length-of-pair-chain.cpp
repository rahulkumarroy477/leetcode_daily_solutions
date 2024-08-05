class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(),pairs.end());

        vector<int> t(n,1);

        int ans = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    t[i] = max(t[i], 1 + t[j]);
                }
            }

            ans = max(ans,t[i]);
        }

        return ans;
    }
};