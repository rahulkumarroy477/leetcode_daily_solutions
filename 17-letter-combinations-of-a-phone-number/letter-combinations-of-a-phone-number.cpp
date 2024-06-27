class Solution {
public:
    unordered_map<char,string> mp = {
       {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
       {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    void solve(string &temp,int i,string digits,vector<string> &ans){
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }

        for(char ch: mp[digits[i]]){
            temp.push_back(ch);
            solve(temp,i+1,digits,ans);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)  return {};
        vector<string> ans;
        string temp;
        solve(temp,0,digits,ans);
        return ans;
    }
};