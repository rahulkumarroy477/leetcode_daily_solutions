class Solution {
bool susbsetSum(vector<int> &nums,int sum){
    int n = nums.size();
    vector<bool> prev(sum+1,false);
    prev[0] = true;     // sum 0 is always possible

    vector<bool> curr(prev.begin(),prev.end());

    for(int i = 1;i<=n;i++){
        for(int target = 1;target<=sum;target++){
            if(nums[i-1]<=target){
                curr[target] = prev[target] || prev[target - nums[i-1]];
            }
            else curr[target] = prev[target];
        }

        prev = curr;
    }

    return prev[sum];

}
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int &x:nums)
            totalSum += x;
        
        if((totalSum&1) == 1) return false;

        return susbsetSum(nums,totalSum/2);
    }
};