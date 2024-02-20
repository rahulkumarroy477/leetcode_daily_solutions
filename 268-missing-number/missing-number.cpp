class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxi = -1;
        bool zero = false;
        for(auto x:nums){
            if(x==0)    zero = true;
            maxi = max(maxi,x);
            sum += x;
        }
        
        int missing = (maxi*(maxi+1))/2 - sum;
        
        if(missing) return missing;
        return zero?maxi+1:0;
    }
};