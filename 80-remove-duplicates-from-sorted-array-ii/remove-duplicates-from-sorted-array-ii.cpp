class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // hashing
        
        int n = nums.size();
        map<int,int> mp;
        for(const auto &x:nums){
            mp[x]++;
        }
        int i = 0;
        for(const auto &x:mp){
            int a = x.first;
            int freq = x.second;
            if(freq==1){
                nums[i++] = a;
            }else{
                nums[i] = nums[i+1] = a;
                i += 2;
            }
        }
        return i;
        
    }
};