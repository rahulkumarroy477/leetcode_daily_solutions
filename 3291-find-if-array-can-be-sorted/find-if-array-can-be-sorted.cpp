class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        // sort the array in groups with same
        // setbits but are adjacent
        int n = nums.size();
        bool swapped = true;
        for(int i = 0;i<n;i++){
            swapped = false;

            for(int j = 0;j<n-i-1;j++){
                if(nums[j]<=nums[j+1]){   // no swap required
                    continue;
                }
                else{
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    }else return false;
                }
            }

            if(!swapped)    break;
        }
        // for(int x:nums) cout<<x<<" ";
        return true;


    }
};