class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        int ans = -1;
        while(i<n1 and j<n2){
            if(nums1[i]<nums2[j])   i++;
            else if(nums1[i]>nums2[j])  j++;
            else{
                ans = nums1[i];
                break;
            }
        }
        return ans;
    }
};