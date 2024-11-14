class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, 
    vector<string>& keyTime) {
        vector<string> ans;

        unordered_map<string,vector<int>> mp;

        int n = keyName.size();
        for(int i = 0; i<n; i++){

            int hr = stoi(keyTime[i].substr(0,2));
            int mn = stoi(keyTime[i].substr(3,2));

            int totalMn = hr*60 + mn;
            mp[keyName[i]].push_back(totalMn);
        }
        
        for(auto &it: mp){
            auto &vec = it.second;
            sort(begin(vec),end(vec));

            for(int i = 2; i < it.second.size(); i++){
                if(vec[i] - vec[i-2] <= 60){
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};