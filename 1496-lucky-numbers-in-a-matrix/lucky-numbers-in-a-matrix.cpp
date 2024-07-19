class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> st;
        // vector<int> rowMin;
        vector<int> colMax(matrix[0].begin(),matrix[0].end());
        // rowMin.push_back(*min_element(matrix[0].begin(),matrix[0].end()));
        for(int i = 0;i<m;i++){
            int minRowElem = INT_MAX;
            for(int j = 0;j<n;j++){
                minRowElem = min(minRowElem, matrix[i][j]);
                colMax[j] = max(colMax[j],matrix[i][j]);
            }
            st.insert(minRowElem);
        }
        for(int x:colMax){
            if(st.find(x)!=st.end())
                return {x};
            st.insert(x);
        }
        
        return {};
    }
};