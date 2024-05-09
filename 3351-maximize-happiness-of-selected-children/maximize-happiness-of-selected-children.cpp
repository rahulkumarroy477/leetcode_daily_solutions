class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(),happiness.end());
        
        long long happiness_value = 0;
        for(int i =0;i<k;i++){
            int curr_happiness = pq.top();
            pq.pop();
            
            if(curr_happiness-i >=0){
                happiness_value += curr_happiness-i;
            }
        }
        return happiness_value;
    }
};