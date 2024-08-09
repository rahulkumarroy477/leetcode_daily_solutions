class Solution {
    bool isSquareMatrix(vector<vector<int>> &temp){
        int diag1 = 0, diag2 = 0;
        set<int> st;
        int prev = -1;

        for(int i = 0; i < 3; i++) {
            int rowSum = 0;
            int colSum = 0;

            for(int j = 0; j < 3; j++) {
                int num = temp[i][j];
                if (i == j) diag1 += num;

                if (i + j == 2) diag2 += num;

                rowSum += num;
                colSum += temp[j][i];

                if (num < 1 || num > 9 || st.find(num) != st.end())  
                    return false;

                st.insert(num);
            }

            if (prev == -1) prev = rowSum;
            else if (prev != rowSum || prev != colSum) return false;
        }
        return prev == diag1 && prev == diag2;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m<3 || n<3)  return 0;
        vector<vector<int>> temp(3,vector<int>(3));

        int count = 0;
        for(int i = 2;i<m;i++){
            for(int j = 2;j<n;j++){
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        temp[k][l] = grid[i+k-2][j+l-2];
                        // cout<<grid[i+k-2][j+l-2]<<" ";
                    }
                    // cout<<endl;
                }

                if(isSquareMatrix(temp))    count++;
                // cout<<endl;
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        cout<<temp[k][l]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
        }

        return count;

    }
};