class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        int newSt = newInterval[0];
        int newEnd = newInterval[1];
        int i = 0;
        vector<vector<int>> ans;

        // find position where it lies
        while(i<n && intervals[i][1]<newSt){
            ans.push_back(intervals[i]);
            i++;
        }
        // merge the intervals

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],
            newInterval[0]);
            newInterval[1] = max(intervals[i][1],
            newInterval[1]);
            i++;
        }

        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        

        return ans;
    }
};