class Solution {
public:
    int countOdds(int low, int high) {
        int odds = 0;
        if(high%2==0)   odds = high/2;
        else odds = high/2+1;

        cout<<odds<<endl;
        if(low%2==0)   odds -= low/2;
        else odds -= low/2;
        cout<<odds<<endl;

        return odds;
    }
};