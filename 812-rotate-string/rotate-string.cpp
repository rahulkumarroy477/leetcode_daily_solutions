class Solution {
public:
    bool rotateString(string s, string goal) {
        // get the first char index in second

        if(s.size() != goal.size()) return false;

        int pos = (s+s).find(goal);
        return pos != -1;
    }
};