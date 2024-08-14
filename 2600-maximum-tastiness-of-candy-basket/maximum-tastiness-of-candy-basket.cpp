class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(begin(price),end(price));

        int low = 0, high = INT_MAX;
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            int last = price[0];
            int count = 1;

            for(int i = 1;i<n;i++){
                if(price[i]-last>=mid){
                    last = price[i];
                    count++;
                }
            }

            if(count>=k){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};