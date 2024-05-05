class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        // only three elements
        
        if(arr[1]>arr[0] and arr[1]>arr[2]) return 1;
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]) return mid;
            
            // left part
            if(arr[mid]>arr[mid-1]) low = mid+ 1;
            else high = mid-1;
        }
        return -1;
    }
};