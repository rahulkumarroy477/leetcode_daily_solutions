class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        vector<int> count(32,0);

        for(int num: candidates){
            for(int i = 0;i<32;i++){
                if((num&(1<<i))){
                    count[i]++;
                }
            }
        }

        int maxi = *max_element(count.begin(),count.end());

        return maxi;
    }
};