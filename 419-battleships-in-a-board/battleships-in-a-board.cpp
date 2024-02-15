class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='X'){
                    bool valid = true;
                    if(i-1>=0 and board[i-1][j]=='X')   valid = false;
                    if(j-1>=0 and board[i][j-1]=='X')   valid = false;
                    
                    if(valid)   count++;
                }
            }
        }
        
        return count;
    }
};