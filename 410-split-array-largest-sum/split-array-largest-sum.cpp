class Solution {
    bool solve(vector<int>&nums,int mid, int k){
        int sum = 0;

        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sum>mid){
                sum = nums[i];
                k--;
                if(k==0)    return false; 
            }
        }

        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(solve(nums,mid,k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};