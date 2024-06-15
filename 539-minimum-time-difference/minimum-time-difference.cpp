class Solution {
public:
    int hourTomin(string time){
        // time --> "HH:MM"
        int hr = ((time[0]-'0')*10 + (time[1]-'0'))*60;
        int min = ((time[3]-'0')*10 + (time[4]-'0'));

        int totalMin = hr + min;
        return totalMin;

    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timePointsMinutes;
        for(auto x:timePoints){
            timePointsMinutes.push_back(hourTomin(x));
        }
        sort(timePointsMinutes.begin(),timePointsMinutes.end());
        int n = timePoints.size();
        int ans = INT_MAX;
        for(int i = 1;i<n;i++)
        {
            ans = min(ans,timePointsMinutes[i]-timePointsMinutes[i-1]);
        }

        // Handling circular time difference
        int circularDiff = 1440 + timePointsMinutes[0] - timePointsMinutes[n-1];
        ans = min(ans,circularDiff);

        return ans;

    }
};