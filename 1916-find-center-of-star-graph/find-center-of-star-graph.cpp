class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        if(a==c or a==d)    return a;
        else if(b==c or b==d)   return b;
        return a;
    }
};