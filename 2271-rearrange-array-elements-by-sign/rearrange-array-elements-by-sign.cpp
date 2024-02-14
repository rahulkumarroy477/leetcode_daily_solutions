class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;
        for(auto x:nums){
            if(x>0) pos.push_back(x);
            else neg.push_back(x);
        }
        for(int i = 0,j=0;i<n;i+=2,j++){
            nums[i] = pos[j];
            nums[i+1] = neg[j];
        }
        return nums;
    }
};