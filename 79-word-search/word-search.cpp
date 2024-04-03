class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(int i, int j, int curr,vector<vector<char>>& board, string &word){
        // all words khatam
        if(curr == word.length())   return true;
        // boundary check
        
        if(i>=m || j>=n || i<0 || j<0 || board[i][j] == '$')
            return false;
        if(board[i][j] != word[curr])
            return false;
        
        char ch = board[i][j];
        board[i][j] = '$';
        
        // traverse in all directions
        
//         vector<int> cols = {-1,0,1,0};
//         vector<int> rows = {0,1,0,-1};
        
//         for(int k = 0;k<4;k++){
//             int new_i = i + rows[k];
//             int new_j = j + cols[k];
            
//             if(find(new_i,new_j, curr+1,board,word)==true)  
//                 return true;
//         }
        for(auto &dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(find(new_i,new_j, curr+1,board,word)==true)  
                return true;
            
        }
        
        board[i][j] = ch;
        
        // character nhi mila
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0] && find(i,j,0,board,word))  return true;
            }
        }
        return false;
    }
};