class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currTime = 1;
        long long totalWaitingTime = 0;
        int n = customers.size();
        for(const auto &customer:customers){
            int arrival = customer[0];
            int time = customer[1];
            if(arrival>currTime)    currTime = arrival;
            currTime += time;
            totalWaitingTime += currTime - arrival;
        }

        return totalWaitingTime/(double)n;
    }
};