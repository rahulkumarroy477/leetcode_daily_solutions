class Solution {
public:
    int countDigits(int num){
        if(num == 0)    return 1;
        int count = 0;
        if(num < 0){
            num = -num;
            count = 1;
        }
        while(num){
            count++;
            num /= 10;
        }
        return count;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int> ans(col,0);
        for(int i = 0;i<col;i++){
            int curr = 0;
            for(int j = 0;j < row; j++){
                curr = max(curr,countDigits(grid[j][i]));
            }
            ans[i] = curr;
        }

        return ans;
        
    }
};