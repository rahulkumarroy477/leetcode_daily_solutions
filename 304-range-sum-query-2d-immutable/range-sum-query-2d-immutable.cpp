class NumMatrix {
public:
    int m, n;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        prefix.resize(m,vector<int>(n,0));
        // calculate prefix sum
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){

                prefix[i][j] = matrix[i][j];
                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];

                if(i>0 and j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = prefix[r2][c2];
        if(r1>0)  sum -= prefix[r1-1][c2];
        if(c1>0)  sum -= prefix[r2][c1-1];

        if(r1>0 and c1>0)   sum += prefix[r1-1][c1-1];

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */