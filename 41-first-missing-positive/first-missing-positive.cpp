class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==1)  return 2;
            else return 1;
        }
        
        sort(nums.begin(),nums.end());
        bool found = binary_search(nums.begin(),nums.end(),1);
        if(!found)  return 1;
        
        long long int sub;
        for(int i = 1;i<n;i++){
            sub = nums[i]-nums[i-1];
            if(sub>1 and (nums[i-1]+1)>0)    
                return nums[i-1]+1;
        }
        return nums[n-1]+1;
            
    }
};