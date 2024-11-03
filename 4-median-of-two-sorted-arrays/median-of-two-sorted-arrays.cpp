class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        int half = total / 2;
        
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = half - mid1;
            
            // Define left and right elements for both arrays
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            // Check if we have a valid median partition
            if (l1 <= r2 && l2 <= r1) {
                // If total is even, return average of max(left side) and min(right side)
                if (total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } 
                // If total is odd, return the min of right side
                else {
                    return min(r1, r2);
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        
        return -1;
    }
};