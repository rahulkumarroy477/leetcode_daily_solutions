class Solution {
public:
    bool checkOnesSegment(string s) {
        // check whether all ones are contiguous or not
        bool prev = false;
        for(char ch:s){
            if(ch=='1'){
                if(prev)    return false;
            }
            else prev = true;
        }

        return true;

    }
};