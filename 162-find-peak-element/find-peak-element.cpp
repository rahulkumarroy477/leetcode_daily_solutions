class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // peak element
        // low < mid < high
        int n = nums.size();
        if(n == 1)  return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            // peak element
            
            if(nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1])    return mid;
            
            if(nums[mid+1]>nums[mid]) 
                low = mid+1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};