class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long,long> mp[n];

        int result = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                
                long common_diff = (long)nums[i] - nums[j];

                long count = 0;
                // total subsequence ending at j
                // subsequence = 1 means there exists atleast two elements in the subsequence
                if(mp[j].find(common_diff)!= mp[j].end()){
                    count = mp[j][common_diff];
                    result += count;
                }

                mp[i][common_diff] += 1 + count;
            }
        }

        return result;
    }
};