class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // storing prefix sum

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int ans = 0;
        // apply subarray sum on columns
        for(int left = 0; left < n; left++) {
            for(int right = left; right < n; right++) {
                
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cumSum = 0;

                for(int i = 0; i < m; i++) {
                    // Calculate the current sum for the rectangle from column left to right
                    cumSum += matrix[i][right] - (left > 0 ? matrix[i][left-1] : 0);
                    
                    // Check if there is a subarray (submatrix) that sums up to target
                    if(mp.find(cumSum - target) != mp.end()) {
                        ans += mp[cumSum - target];
                    }

                    mp[cumSum]++;
                }
            }
        }

        return ans;
    }
};