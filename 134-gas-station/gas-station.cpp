class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // bruteforce

        // int ans = -1;
        // int n = gas.size();
        // for(int i = 0;i<n;i++){
        //     int currGas = gas[i] - cost[i];
        //     if(currGas < 0) continue;

        //     for(int j = 1;j<n;j++){
        //         currGas += gas[(i+j)%n]-cost[(i+j)%n];

        //         if(currGas<0)   break;
        //     }

        //     if(currGas >= 0){
        //         return i;
        //     } 
        // }

        // return -1;



        int n = gas.size();
        // total gas that can be filled >= totalCost 
        int total_gas = accumulate(gas.begin(),gas.end(),0);
        int total_cost = accumulate(cost.begin(),cost.end(),0);

        if(total_cost>total_gas)    return -1;  

        // filtered out the not possible case now atleast one answer will exist

        int total = 0;
        int idx = 0;
        for(int i = 0;i<n;i++){
            total += gas[i]-cost[i];

            if(total < 0){
                total = 0;
                idx = i+1;
            }
        }

        return idx;

    }
};