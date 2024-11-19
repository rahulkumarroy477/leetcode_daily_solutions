class Solution {
public:

    int m, n;
    bool ok(int r, int c){
        return (r>=0 && c>=0 && r<m && c<n);
    }
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    
    bool solve(int r, int c, int idx, vector<vector<char>>& board, string &word){

        if(idx == word.length())    return true;

        if(!ok(r,c) || board[r][c] != word[idx])
            return false;

        char ch = board[r][c];
        board[r][c] = '*';
        // traverse in 4 directions
        for(auto [dr, dc]: dir){
            int nr = r + dr;
            int nc = c + dc;
            if(solve(nr, nc, idx+1, board, word))
                return true;
            
        }

        board[r][c] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false; // Handle edge cases
        }
        m = board.size();
        n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(solve(i,j,0,board, word))
                    return true;
            }
        }

        return false;
    }
};