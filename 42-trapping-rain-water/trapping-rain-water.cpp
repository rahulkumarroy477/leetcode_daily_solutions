class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> left_max = left_max_array(height,n);
        vector<int> right_max = right_max_array(height,n);
        
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            int w = min(left_max[i],right_max[i])-height[i];
            sum += w;
        }
        return sum;
    }
    vector<int> left_max_array(vector<int> &nums,int n){
        vector<int> ans(n);
        ans[0] = nums[0];
        
        for(int i =1;i<n;i++){
            ans[i] = max(nums[i],ans[i-1]);
        }
        return ans;
    }
    
    vector<int> right_max_array(vector<int> &nums,int n){
        vector<int> ans(n);
        
        ans[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            ans[i] = max(nums[i],ans[i+1]);
        }
        return ans;
    }
};