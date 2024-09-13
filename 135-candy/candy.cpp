class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1),right(n,1);
        
        // distribute choclate from left to right
        for(int i =1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = 1 + left[i-1];
            }
        }
        // right to left
        for(int i = n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = 1 + right[i+1];
            }
        }
        // for(int x:left)     cout<<x<<" ";
        // cout<<endl;
        // for(int x:right)    cout<<x<<" ";
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += max(left[i],right[i]);
        }

        return sum;
    }
};