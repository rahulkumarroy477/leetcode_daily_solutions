class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        // e o e o e o e o e
        // 1 1 2 3 3 4 4 8 8 
        if(nums[0]!=nums[1])    return nums[0];
        if(nums[n-1]!=nums[n-2])    return nums[n-1];
        
        int low = 1;
        int high = n - 2;
        
        while(low <= high){
            int mid = low + (high-mid)/2;
            
            if(nums[mid-1]!= nums[mid] and nums[mid]!=nums[mid+1])  return nums[mid];
            
            //  left part eliminates
            if((mid%2 == 1 and nums[mid-1]==nums[mid]) || (mid%2==0 and nums[mid] == nums[mid+1]))
                low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};