class Solution {
    int secondItr(bool check,int x,int y,vector<char> &temp){
        int points = 0;
        vector<char> st;
        for(char ch:temp){
            if(!st.empty()){
                if(check && ch == 'a' && st.back()=='b')
                {
                    points += y;
                    st.pop_back();
                }
                else if(!check && ch == 'b' && st.back() == 'a'){
                    points += x;
                    st.pop_back();
                }
                else st.push_back(ch);
            }

            else st.push_back(ch);

        }
        return points;

    }
public:
    int maximumGain(string s, int x, int y) {
        bool check = x>y;

        int points = 0;
        vector<char> st;
        for(char ch:s){
            if(!st.empty()){
                if(check && ch == 'b' && st.back()=='a')
                {
                    points += x;
                    st.pop_back();
                }
                else if(!check && ch == 'a' && st.back() == 'b'){
                    points += y;
                    st.pop_back();
                }
                else st.push_back(ch);
            }

            else st.push_back(ch);

        }
        points += secondItr(check,x,y,st);
        return points;
    }
};