class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        
        int i = 0, j = 0;
        while(i<n1 and j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                if(ans.size()==0 or ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};