class Solution {
public:
    string multiply(string s1, string s2) {
        if(s1=="0" or s2=="0")  return "0";
        string ans;
        for(int i = s2.length()-1;i>=0;i--){
            ans = add_str(ans,mutliply_str_char(s1,s2[i]));
            s1.push_back('0');
        }
        return ans;
    }
    
    string mutliply_str_char(string s,char c){
        if(c=='1')  return s;
        short x = c - '0';
        string ans;
        short carry = 0;
        for(int i = s.length()-1;i>=0;i--){
            short y = s[i] - '0';
            short mult = x*y;
            // cout<<x<<"*"<<y<<" = "<<mult<<endl;
            // cout<<(mult+carry)%10<<" ";
            ans.push_back((mult+carry)%10+'0');
            carry = (mult+carry)/10;
            // cout<<carry<<endl;
        }
        if(carry)   ans.push_back(carry+'0');

        reverse(ans.begin(),ans.end());
        return ans;
    }
    string add_str(string s1,string s2){
        if(s1.length()==0)  return s2;

        int i = s1.length()-1;
        int j = s2.length()-1;
        string ans;
        short carry = 0;
        while(i>=0 or j>=0){
            short x = 0,y=0;
            if(i>=0)
                x = s1[i--] - '0';
            if(j>=0)
                y = s2[j--] - '0';
            short add = x+y;
            // cout<<x<<"+"<<y<<" = "<<add<<endl;
            // cout<<(add+carry)%10<<" ";
            ans.push_back((add+carry)%10+'0');
            carry = (add+carry)/10;
        }

        if(carry)   ans.push_back(carry+'0');

        reverse(ans.begin(),ans.end());
        return ans;
    }
};