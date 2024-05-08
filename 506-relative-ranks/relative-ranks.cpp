class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // all values are unique
        
        int n = score.size();
        vector<int> temp(score.begin(),score.end());
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[score[i]] = i;
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        vector<string> ans(n);
        
        for(int i = 0;i<n;i++){
            if(i==0)    ans[mp[temp[i]]] = "Gold Medal";
            else if(i==1)   ans[mp[temp[i]]] = "Silver Medal";
            else if(i == 2) ans[mp[temp[i]]]  = "Bronze Medal";
            else{
                ans[mp[temp[i]]] = to_string(i+1);
            }
        }
        
        return ans;
    }
};