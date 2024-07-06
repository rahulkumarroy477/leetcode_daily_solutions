class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n)  return time+1;

        int q = time/(n-1);
        int rem = time%(n-1);

        if(q&1==1)  return n - rem;
        return rem+1;
    }
};