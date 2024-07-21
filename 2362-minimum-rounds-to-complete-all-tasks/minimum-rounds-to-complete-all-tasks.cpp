class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;

        for(int x:tasks)
            mp[x]++;
        int round = 0;
        for(auto it:mp){
            int freq = it.second;

            if(freq < 2)    return -1;

            if(freq%3 == 0) round += freq/3;
            else round += freq/3 + 1;
        }

        return round;
    }
};