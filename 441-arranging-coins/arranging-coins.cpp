class Solution {
public:
    int arrangeCoins(int n) {
        // summation rule  n * (n+1)/2

        // binary search
        int st = 0, end = n;
        int ans = 0;
        while(st<=end){
            int mid = st + (end-st)/2;
            long long sumToMid = (long long)mid*(mid+1)/2;
            if(sumToMid<=n){
                ans = mid;
                st = mid +1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};