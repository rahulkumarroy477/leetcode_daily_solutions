class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i = n-1;i>=0;i--){
            // get the correct index

            int maxIdx = max_element(arr.begin(),
            arr.begin()+i+1) - arr.begin();
            
            if(maxIdx != i){
                ans.push_back(maxIdx+1);
                reverse(arr.begin(),arr.begin()+maxIdx+1);

                ans.push_back(i+1);
                reverse(arr.begin(),arr.begin()+i+1);
            }
        }

        return ans;
    }
};