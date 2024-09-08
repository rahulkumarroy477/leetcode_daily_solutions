class Solution {
public:
    int myAtoi(string s) {
        
        // remove spaces
        int i = 0, n = s.length();

        while(i<n && s[i]==' '){
            i++;
        }

        // check empty string
        if(i>=n)    return 0;

        // check sign
        bool pos = true;
        if(s[i] == '+' || s[i] == '-'){
            pos = (s[i] == '+');
            i++;
        }

        long result = 0;
        while(isdigit(s[i])){
            result = result * 10 + (s[i]-'0');

            if(pos && result > INT_MAX)    return INT_MAX;
            else if(-result < INT_MIN)  return INT_MIN;

            i++;
        }

        return pos ? result : -result;
    }
};