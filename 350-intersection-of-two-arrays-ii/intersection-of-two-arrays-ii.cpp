class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // O(nlogn)
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int n1 = nums1.size();
        // int n2 = nums2.size();
        // int i = 0, j = 0;
        // vector<int> ans;

        // while(i<n1 && j<n2){
        //     if(nums1[i]==nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        //     else if(nums1[i]<nums2[j]){
        //         i++;
        //     }
        //     else j++;
        // }

        // O(n1+n2)
        unordered_map<int,int> mp;
        vector<int> ans;
        for(const int& x:nums1){
            mp[x]++;
        }

        for(const int &x:nums2){
            if(mp.find(x)!=mp.end()){
                ans.push_back(x);
                mp[x]--;
                if(mp[x]==0){
                    mp.erase(x);
                }
            }
        }

        return ans;
    }
};