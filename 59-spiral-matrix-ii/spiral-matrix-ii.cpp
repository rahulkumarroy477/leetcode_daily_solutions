class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,1));
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int count = 1;
        while(top<=bottom and left<=right){
            for(int i = left;i<=right;i++){
                ans[top][i] = count++;
            }
            top++;
            for(int i = top;i<=bottom;i++){
                ans[i][right] = count++;
            }
            right--;
            
            if (top <= bottom) { // Check if there's a row left to traverse
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = count++;
                }
                bottom--;
            }
            
            if (left <= right) { // Check if there's a column left to traverse
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = count++;
                }
                left++;
            }
        }
        
        return ans;
    }
};