class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        if(k==1){
            for(int i = 0;i<n;i++)
                ans.push_back((double)nums[i]);
            return ans;
        }
        int i = 0;
        multiset<int> left,right;

        auto balanceSets = [&]() {
            if (left.size() > right.size() + 1) {
                right.insert(*left.rbegin());
                left.erase(--left.end());
            } else if (right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };
        while(i<k){
            if(left.empty() || *left.rbegin() >= nums[i]){
                left.insert(nums[i]);
            }
            else{
                right.insert(nums[i]);
            }

            balanceSets();
            i++;
        }

        int totalSize = left.size() + right.size();
        if (totalSize % 2 == 1) {
            ans.push_back((double)*left.rbegin());
        } else {
            ans.push_back((*left.rbegin() + (double)*right.begin()) / 2);
        }


        while(i<n){
            int delNum = nums[i-k];

            if(left.find(delNum)!=left.end()){
                left.erase(left.find(delNum));
            }
            else{
                right.erase(right.find(delNum));
            }
            balanceSets();
            if (nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }

            balanceSets();

            totalSize = left.size() + right.size();
            if (totalSize % 2 == 1) {
                ans.push_back((double)*left.rbegin());
            } else {
                ans.push_back((*left.rbegin() + (double)*right.begin()) / 2);
            }

            i++;
            
        }
        return ans;
    }
};