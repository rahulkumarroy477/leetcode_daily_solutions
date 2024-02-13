class Solution {
public:
    bool isValidRow(int i,vector<vector<char>>& board){
        set<char> st;
        for(int j = 0;j<9;j++){
            if(board[i][j]!='.'){
                if(st.count(board[i][j]))   return false;
                else st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidColumn(int j,vector<vector<char>> &board){
        set<char> st;
        for(int i=0;i<9;i++){
            if(board[i][j]!='.'){
                if(st.count(board[i][j]))   return false;
                else st.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidQuadrant(int row, int col, vector<vector<char>>& board) {
        set<char> st;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] != '.') {
                    if (st.count(board[i][j])) return false;
                    else st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check rows
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(i, board)) return false;
        }
        
        // Check columns
        for (int j = 0; j < 9; j++) {
            if (!isValidColumn(j, board)) return false;
        }
        
        // Check quadrants
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidQuadrant(i, j, board)) return false;
            }
        }
        
        return true;
        
    }
};