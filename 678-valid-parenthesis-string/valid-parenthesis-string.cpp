class Solution {
public:
    int t[101][101];
    int n;
    bool solve(int i,int count,string s){
        // base case
        if(i==n){
            return count == 0;
        }
        
        if(t[i][count]!=-1) return t[i][count];
        bool isValid = false;
        
        if(s[i] == '('){
            isValid |= solve(i+1,count+1,s);
        }
        else if(s[i] == '*'){
            // three choices
            isValid |= solve(i+1,count+1,s);    // open bracket
            isValid |= solve(i+1,count,s);      // empty
            if(count>0) isValid |= solve(i+1,count-1,s);   // close bracket
        }
        else if(count>0) 
            isValid |= solve(i+1,count-1,s);
        
        return t[i][count] = isValid;
    }
    bool checkValidString(string s) {
        // for * we have three choices
        memset(t,-1,sizeof(t));
        n = s.length();
        return solve(0,0,s);
    }
};