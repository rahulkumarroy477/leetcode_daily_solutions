class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0;
        int n = tickets.size();
        int i = 0;
        while(i<=k){
            totalTime += min(tickets[i],tickets[k]);
            i++;
        }
        while(i<n){
            totalTime += min(tickets[i],tickets[k] - 1);
            i++;
        }
        return totalTime;
    }
};