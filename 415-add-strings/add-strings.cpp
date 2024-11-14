class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        string ans = "";
        int carry = 0;
        int sum;
        while(i>=0 || j>=0 || carry){
            sum = 0;
            if(i>=0){
                sum += num1[i--] - '0';
            }

            if(j>=0){
                sum += num2[j--] - '0';
            }

            sum += carry;
            ans.push_back('0' + sum%10);
            carry = sum/10;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};