class Solution {
public:
    unordered_map<char,string> mp = {
       {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
       {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    vector<string> ans;
    string temp;
    void solve(int i,string digits){
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }

        for(char ch: mp[digits[i]]){
            temp.push_back(ch);
            solve(i+1,digits);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)  return {};
        solve(0,digits);
        return ans;
    }
};