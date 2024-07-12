class Solution {
private:
    int removeSubstr(string &s,char start,char end,int point){
        int score = 0;
        vector<char> st;
        for(char ch:s){
            if(!st.empty() && ch==end && st.back()==start)
            {
               score += point; 
               st.pop_back();
            }
            else
                st.push_back(ch);
        }
        s = string(st.begin(),st.end());
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        if(x>y){
            totalPoints += removeSubstr(s,'a','b',x);
            totalPoints += removeSubstr(s,'b','a',y);
        }
        else{
            totalPoints += removeSubstr(s,'b','a',y);
            totalPoints += removeSubstr(s,'a','b',x);
        }

        return totalPoints;
    }
};