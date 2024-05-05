class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        while(low<=high){
            // left part is sorted
            
            int mid = low + (high-low)/2;
            
            // array already sorted
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            
            if(nums[low]<=nums[mid]){   // equal for single and two elements
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else{
                
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};