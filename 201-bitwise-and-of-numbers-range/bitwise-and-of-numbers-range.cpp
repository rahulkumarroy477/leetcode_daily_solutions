class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
//         if (left == 0)  return 0;
        
//         int count = 0;
//         while(left!=right){
//             left = left>>1;
//             right = right>>1;
//             count++;
//         }
        
//         left = left<<count;
        
        while(right>left){
            right = (right&(right-1));  // n & (n-1)    right me saare set bit ko peldo
        }
        
        return right;
    }
};