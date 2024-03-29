class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        long long ans = 0;
        int i = 0,j=0;
        while(j<n){
            if(nums[j]==maxi)   count++;
            while(count>=k){
                ans += n-j;
                if(nums[i]==maxi)   count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};