class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // for(int i = 0;i<m;i++){
        //     int low = 0, high = n-1;
        //     while(low <= high){
        //         int mid = low + (high - low)/2;

        //         if(matrix[i][mid] == target)    return true;
        //         else if(matrix[i][mid] < target)    low = mid+1;
        //         else high = mid-1;
        //     }
        // }

        int i = 0, j = n-1;
        while(i<m && j>=0){

            if(matrix[i][j] == target)  return true;
            else if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }

        return false;
    }
};