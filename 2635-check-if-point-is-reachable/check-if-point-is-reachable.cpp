class Solution {
public:
    bool isReachable(int x, int y) {
        // int gc = __gcd(x,y);
        // return (gc&(gc-1))==0;    // even check

        int i = x, j = y;
        while(i>0 and j>0){
            while(i%2==0)   i/=2;
            while(j%2==0)   j/=2;

            if(i>j) i-=j;
            else if(j>i)    j-=i;
            else{
                if(i==1 && j==1)    return 1;
                else i-=j;  // yaha either i-= j or j-= i
            }
        }
        return 0;
    }
};