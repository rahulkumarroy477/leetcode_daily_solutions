class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0)  return 0;
        
        int count = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            count++;
        }
        
        left = left<<count;
        
        return left;
    }
};