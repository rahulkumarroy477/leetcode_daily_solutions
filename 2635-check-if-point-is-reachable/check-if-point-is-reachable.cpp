class Solution {
public:
    bool isReachable(int x, int y) {
        int gc = __gcd(x,y);
        return (gc&(gc-1))==0;    // even check
    }
};