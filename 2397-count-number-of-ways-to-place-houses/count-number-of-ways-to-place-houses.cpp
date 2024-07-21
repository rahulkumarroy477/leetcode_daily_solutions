class Solution {
    int MOD = 1e9+7;
    long long t[10001];
    long long solve(int idx, int n){
        if(idx >=n) return 1;

        if(t[idx]!=-1)  return t[idx];
        // take
        long long take = solve(idx+2,n);
        // skip
        long long skip = solve(idx+1,n);

        return t[idx] = (take + skip)%MOD;
    }
public:
    int countHousePlacements(int n) {
        // dp for one row
        memset(t,-1,sizeof(t));
        long long ans = solve(0,n);
        return (ans*ans)%MOD;
    }
};