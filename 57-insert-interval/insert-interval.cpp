class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0)    return {newInterval};
        vector<vector<int>> ans;
        
        // add all elements that end before interval
        int i = 0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        // merging from newInterval
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        // remaining elements
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};