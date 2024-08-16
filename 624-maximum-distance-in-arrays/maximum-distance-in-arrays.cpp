class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(),arrays.end());

        int ans = 0;
        int n = arrays.size();
        int prevMax = arrays[0].back();
        int prevMin = arrays[0][0];
        for(int i = 1;i<n;i++){
            ans = max(ans,abs(prevMax-arrays[i][0]));
            ans = max(ans,abs(prevMin-arrays[i].back()));

            prevMax = max(prevMax,arrays[i].back());
            prevMin = min(prevMin,arrays[i][0]);
        }

        for(auto y:arrays){
            for(int x:y)
                cout<<x<<" ";
            cout<<endl;
        }

        return ans;
    }
};