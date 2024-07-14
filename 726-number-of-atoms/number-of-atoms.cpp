class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>()); 
        
        for (int i = 0; i < n; i++) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
            } else if (formula[i] == ')') {
                auto mp = st.top();
                st.pop();
                i++;
                
                string multiplier = "";
                while (i < n && isdigit(formula[i])) {
                    multiplier.push_back(formula[i]);
                    i++;
                }
                
                int multi = multiplier.empty() ? 1 : stoi(multiplier);
                for (auto &it : mp) {
                    it.second *= multi;
                }
                
                // Merge with the top of the stack
                for (auto &it : mp) {
                    st.top()[it.first] += it.second;
                }
                i--;
            } else {
                string atom;
                atom.push_back(formula[i++]);
                while (i < n && islower(formula[i])) {
                    atom.push_back(formula[i++]);
                }
                
                string currCount = "";
                while (i < n && isdigit(formula[i])) {
                    currCount.push_back(formula[i++]);
                }
                
                st.top()[atom] += currCount.empty() ? 1 : stoi(currCount);
                i--;
            }
        }

        map<string, int> sortedMp(st.top().begin(), st.top().end());
        string ans = "";
        for (auto it : sortedMp) {
            ans.append(it.first);
            if(it.second>1)
                ans.append(to_string(it.second));
        }

        return ans;
    }
};