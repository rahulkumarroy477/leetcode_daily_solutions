class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.length()==1)   return s;
        
        int n = s.length();
        int oneCount = 0;
        for(const char &ch:s){
            if(ch=='1') oneCount++;
        }
        string ans;
        while(oneCount!=1){
            ans.push_back('1');
            oneCount--;
        }
        
        // push zeroes
        int ans_size = ans.length();
        while(ans_size!=n-1){
            ans.push_back('0');
            ans_size++;
        }
        ans.push_back('1');
        
        return ans;
    }
    
};