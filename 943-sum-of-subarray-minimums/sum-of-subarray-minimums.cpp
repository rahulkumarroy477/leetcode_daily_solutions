class Solution {
    vector<int> get_nse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> get_pse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = get_pse(arr);
        vector<int> nse = get_nse(arr);
        int total = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + 
            (left*(long long)right*arr[i])%MOD)%MOD;
        }

        return total;
    }
};