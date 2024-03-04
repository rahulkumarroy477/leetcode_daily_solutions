class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        /** two cases
            
        **/ 
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int result = 0,score = 0;
        // set<int> st(tokens.begin(),tokens.end());
        // find the minimum
        int i = 0, j = n-1;
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                i++;
                score++;
                result = max(result,score);
            }
            else if(score>0){
                power += tokens[j];
                j--;
                score--;
            }
            else break;
        }
        return result;
    }
};