class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1;i>=0;i--){
            if(carry==0)    break;
            if(digits[i]+carry>9){
                digits[i] = (digits[i]+carry)%10;
            }
            else{
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }
        if(carry)   digits.insert(digits.begin(),1);
    
        return digits;  
    }
    
    
};