class Solution {
public:
    // void swap(int& a, int& b)
    // {
    //     a=a+b;
    //     b=a-b;
    //     a=a-b;
    // }
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k)
        {
           switch(nums[j]){
            case 0 : 
                swap(nums[i++],nums[j++]);
                break;
            case 1: 
                j++;
                break;
            case 2: 
                swap(nums[j],nums[k--]);
           }
        }
    }
};