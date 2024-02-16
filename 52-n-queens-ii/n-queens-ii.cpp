class Solution {
public:
    
    void solve(int row,int n,int &count,set<int> &cols,set<int> &posDiag,set<int> &negDiag){
        if(row==n){
            count++;
            return;
        }
        
        for(int col = 0;col<n;col++){
            if(cols.count(col) or posDiag.count(row+col) or negDiag.count(row-col)) continue;
            
            cols.insert(col);
            posDiag.insert(row+col);
            negDiag.insert(row-col);
            
            solve(row+1,n,count,cols,posDiag,negDiag);
            
            cols.erase(col);
            posDiag.erase(row+col);
            negDiag.erase(row-col);
        }
    }
    int totalNQueens(int n) {
        
        int count = 0;
        set<int> cols,posDiag,negDiag;
        
        solve(0,n,count,cols,posDiag,negDiag);
        return count;
    }
};