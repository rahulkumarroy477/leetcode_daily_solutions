class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();

        if(N==1)    return matrix[0][0];

        vector<int> prev(N,0), curr(N,0);
        prev = matrix[0];
        for(int i = 1;i<N;i++){
            for(int j = 0;j<N;j++){
                if (j == 0) {
                curr[j] = matrix[i][j] + 
                    min(prev[j], prev[j+1]);
                } else if (j == N - 1) {
                    curr[j] = matrix[i][j] + 
                    min(prev[j], prev[j-1]);
                } else {
                    curr[j] = matrix[i][j] + 
                    min({prev[j], prev[j-1], 
                    prev[j+1]});
                }
            }
            prev = curr;
            
        }

        return *min_element(curr.begin(),curr.end());
    }
};