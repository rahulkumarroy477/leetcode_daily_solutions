class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch = '1';ch <='9';ch++){
                        if(isValid(board,i,j,ch))
                        {
                            board[i][j] = ch;
                            
                            if(solve(board)==true)    
                                return true;  
                            else 
                                board[i][j] = '.';
                        }
                        
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> &board,int i,int j, char c){
        for(int k = 0;k<9;k++){
            if(board[i][k]==c)  return false;
            if(board[k][j]==c)  return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==c)  return false;
        }
        
        return true;
        
    }
    
};