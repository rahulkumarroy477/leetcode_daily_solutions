class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // all values are unique
        
        int n = score.size();
//         vector<int> temp(score.begin(),score.end());
//         unordered_map<int,int> mp;
//         for(int i = 0;i<n;i++){
//             mp[score[i]] = i;
//         }
//         sort(temp.begin(),temp.end());
//         reverse(temp.begin(),temp.end());
        
        vector<string> ans(n);
        
//         for(int i = 0;i<n;i++){
//             if(i==0)    ans[mp[temp[i]]] = "Gold Medal";
//             else if(i==1)   ans[mp[temp[i]]] = "Silver Medal";
//             else if(i == 2) ans[mp[temp[i]]]  = "Bronze Medal";
//             else{
//                 ans[mp[temp[i]]] = to_string(i+1);
//             }
//         }
        

        
        
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            pq.push({score[i],i});
        }
        int idx = 0;
        while(!pq.empty()){
            auto elem = pq.top();
            pq.pop();
            int i = elem.second;
            if(idx==0)
                ans[i] = "Gold Medal";
            else if(idx==1)
                ans[i] = "Silver Medal";
            else if(idx==2)
                ans[i] = "Bronze Medal";
            else
                ans[i] = to_string(idx+1);
            
            idx++;
        }
        
        return ans;
    }
};