class Solution{
public:
//     bool isSafe(int col,int row,vector<string> board,int n)
//     {
//         //for upper diagonal
//         int tempR = row;
//         int tempC = col;
//         while(row>=0 and col>=0)
//         {
//             if(board[row][col]=='Q')    return false;
//             row--;
//             col--;
//         }
//         // for row
//         row = tempR;
//         col = tempC;
//         while(col>=0)
//         {
//             if(board[row][col]=='Q') return false;
//             col--;
//         }

//         row = tempR;
//         col = tempC;
//         // for lower diagonal
//         while(row<n and col>=0)
//         {
//             if(board[row][col]=='Q')    return false;
//             row++;
//             col--;
//         }

//         return true;
//     }

//     void Solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
//     {
//         if(col==n)  
//         {
//             ans.push_back(board);
//             return;
//         }
//         for(int row =0;row<n;row++)
//         {
//             if(isSafe(col,row,board,n)) 
//             {
//                 board[row][col]='Q';
//                 Solve(col+1,board,ans,n);
//                 board[row][col]='.';
//             }
//         }
//     }
    void solve(int row,vector<string> &board,vector<vector<string>> &ans,set<int> &cols,set<int> &posDiag,set<int> &negDiag){
        int n = board.size();
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col = 0;col<n;col++){
            if(cols.count(col) or posDiag.count(row+col) or negDiag.count(row-col)) continue;
            
            // include
            cols.insert(col);
            posDiag.insert(row+col);
            negDiag.insert(row-col);
            board[row][col] = 'Q';
            
            solve(row+1,board,ans,cols,posDiag,negDiag);
            
            cols.erase(col);
            posDiag.erase(row+col);
            negDiag.erase(row-col);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        set<int> cols;
        set<int> negDiag;   // r - c is constant
        set<int> posDiag;   // r + c is constant
        string s(n,'.');
        for(int i =0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,cols,posDiag,negDiag);
        return ans;
    }
};