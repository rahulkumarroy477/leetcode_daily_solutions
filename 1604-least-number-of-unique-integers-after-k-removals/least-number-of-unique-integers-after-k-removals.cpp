class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto x:arr) mp[x]++;
        
        vector<int> freq_count;
        for(auto elem:mp)   freq_count.push_back(elem.second);
        sort(freq_count.begin(),freq_count.end());
        int i = 0;
        for(;i<freq_count.size();i++){
            if(k>=freq_count[i]){
                k -= freq_count[i];
            }
            else break;
        }
        
        return freq_count.size()-i;
    }
};