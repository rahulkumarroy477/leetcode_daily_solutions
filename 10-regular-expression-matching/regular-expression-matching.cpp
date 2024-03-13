class Solution {
public:
    int t[21][21];
    bool solve(int i, int j,string s,string p){
        if(j==p.length()){
            return i==s.length();
        }
        
        if(t[i][j]!=-1) return t[i][j];
        bool equal_first = false;
        
        if(i<s.length() and (p[j]==s[i] or p[j]=='.'))  equal_first = true;
        
        if(j+1<p.length() and p[j+1]=='*'){
            bool take = equal_first and solve(i+1,j,s,p);
            bool notTake = solve(i,j+2,s,p);
            
            return t[i][j] = take || notTake;
        }
        else{
            return t[i][j] = equal_first and solve(i+1,j+1,s,p);
        }
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};