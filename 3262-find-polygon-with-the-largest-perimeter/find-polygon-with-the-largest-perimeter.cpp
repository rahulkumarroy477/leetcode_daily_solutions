class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = 0;
        long long prev = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // vector<long long> prefix(n);
        // prefix[0] = nums[0];
        // prefix[1] = nums[0];
        // for(int i = 2;i<n;i++){
        //     prefix[i] = prefix[i-1] + nums[i-1];
        // }
        // for(auto x:prefix)    cout<<x<<" ";
        // cout<<endl;
        
        prev = nums[0] + nums[1];
        for(int i = 2;i<n;i++){
            if(prev>nums[i]){
                ans = max(ans, prev + nums[i]);
            }
            // cout<<ans<<" ";
            prev = prev + nums[i];
        }
        return ans==0?-1:ans;
    }
};