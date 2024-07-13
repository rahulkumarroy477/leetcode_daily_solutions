class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indexes(n);
        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }
        
        sort(indexes.begin(), indexes.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; 
        for (int idx : indexes) {
            if (directions[idx] == 'R') {
                st.push(idx); // Robot moving to the right
            } else {
                while (!st.empty() && healths[idx] > 0) {
                    int st_idx = st.top();
                    st.pop();
                    
                    if (healths[st_idx] == healths[idx]) {
                        healths[st_idx] = healths[idx] = 0; // Both robots destroy each other
                    } else if (healths[st_idx] > healths[idx]) {
                        healths[st_idx]--;
                        st.push(st_idx);
                        healths[idx] = 0;
                    } else {
                        healths[idx]--;
                        healths[st_idx] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
