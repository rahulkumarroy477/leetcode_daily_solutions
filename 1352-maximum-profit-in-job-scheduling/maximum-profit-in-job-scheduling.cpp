class Solution {
    int n;
    vector<vector<int>> jobs;
    vector<int> dp;
    int getNextIdx(int st, int val){
        int end = n-1;

        int ans = n;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(jobs[mid][0]>=val){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
    int solve(int idx){
        if(idx>=n)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        // get next index using binary search
        int nextIdx = getNextIdx(idx+1,jobs[idx][1]);

        int take = jobs[idx][2] + solve(nextIdx);
        int notTake = solve(idx+1);

        return dp[idx] =  max(take,notTake);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        jobs.resize(n);
        dp.resize(n,-1);
        // vector<vector<int>> arr;
        for(int i = 0;i<n;i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }

        // auto comp = [&](auto &a, auto &b){
        //     return a[0]<b[0];
        // };
        sort(jobs.begin(),jobs.end());

        return solve(0);
    }
};




