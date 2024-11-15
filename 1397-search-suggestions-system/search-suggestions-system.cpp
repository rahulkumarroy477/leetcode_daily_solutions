class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // sort the products

        sort(begin(products),end(products));

        int l = 0, r = products.size() - 1;
        vector<vector<string>> ans;
        int sWordLen = searchWord.length();
        for(int i = 0; i<sWordLen; i++){

            while(l<=r && (products[l].length() <= i || products[l][i] != searchWord[i]))
                l++;
            while(l<=r && (products[r].length() <= i || products[r][i] != searchWord[i]))
                r--;

            int remaining = min(3,(r - l + 1));
            vector<string> temp;
            for(int j = 0; j<remaining;j++){
                temp.push_back(products[l+j]);
            }
            ans.push_back(temp);
            
            
        }
        return ans;
    }
};