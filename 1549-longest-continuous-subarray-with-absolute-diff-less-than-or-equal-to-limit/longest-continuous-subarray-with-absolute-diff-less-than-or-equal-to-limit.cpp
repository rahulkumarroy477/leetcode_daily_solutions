class Solution {
public:
    typedef pair<int,int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        priority_queue<P,vector<P>> maxHeap;    // maxHeap
        priority_queue<P,vector<P>, greater<P>> minHeap;    // minHeap

        int i = 0;
        int j = 0;
        int maxLen = 0;
        while(j<n){
            maxHeap.push({nums[j],j});
            minHeap.push({nums[j],j});

            while(maxHeap.top().first-minHeap.top().first>limit){
                i = min(maxHeap.top().second,minHeap.top().second)+1;

                while(maxHeap.top().second<i){
                    maxHeap.pop();
                }
                while(minHeap.top().second<i){
                    minHeap.pop();
                }
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};