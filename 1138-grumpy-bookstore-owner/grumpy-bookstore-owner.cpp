class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        // find window jisme count of 1 jyada ho 
        int maxUnsatisfied = 0, currUnsatisfied = 0;
        int n = customers.size();

        int i = 0, j = 0;
        while(j<minutes){
            if(grumpy[j])
                currUnsatisfied += customers[j];
            j++;
        }
        maxUnsatisfied = currUnsatisfied;
        while(j<n){
            if(grumpy[j]==1)
                currUnsatisfied += customers[j];
            if(grumpy[i]==1)
                currUnsatisfied -= customers[i];
            i++; j++;

            maxUnsatisfied = max(maxUnsatisfied, currUnsatisfied);
        }

        int totalSatisfied = maxUnsatisfied;
        for(i = 0;i<n;i++){
            if(grumpy[i]==0)
                totalSatisfied += customers[i];
        }

        return totalSatisfied;
    }
};