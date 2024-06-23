class Solution {
public:
    void helper(int pos,int& count,vector<int> &nums){
        if(pos== nums.size()){
            count++;
            return;
        }

        for(int i = pos;i<nums.size();i++){
            if(nums[i]%pos==0 || pos%nums[i]==0){
                swap(nums[i],nums[pos]);
                helper(pos+1,count,nums);
                swap(nums[i],nums[pos]);
            }
        }
    }
    int countArrangement(int n) {
        // initialisze array with 1 to N
        vector<int> nums(n+1);
        for(int i = 0;i<=n;i++)
            nums[i] = i;
        int count = 0;
        helper(1,count,nums);
        return count;

    }
};