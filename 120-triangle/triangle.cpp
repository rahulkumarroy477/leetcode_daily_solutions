class Solution {
int N;
int t[201][201];
int solve(int i,int j,vector<vector<int>>& triangle){
    if(i==N-1)  return triangle[i][j];
    if(t[i][j]!=-1) return t[i][j];
    int up = solve(i+1,j,triangle);
    int diag = solve(i+1,j+1,triangle);

    return t[i][j] = triangle[i][j] + min(up,diag);
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        N = triangle.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,triangle);
    }
};