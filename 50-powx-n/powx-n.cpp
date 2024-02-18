class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    return 1;
        long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        
        double half = myPow(x,N/2);
        return (N&1)!=0? x*half*half : half * half;
    }
};