class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose of matrix
        
        int n = matrix.size();
        
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // reverse the matrix
        
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};