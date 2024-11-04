class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // get first and second maximum

        int first = INT_MIN, second = INT_MIN;

        for(const int x: nums){
            if(x > first){
                second = first;
                first = x;
            }else if(second < x){
                second = x;
            }
        }

        return (first-1)*(second-1);
    }
};