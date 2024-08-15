class Solution {
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int i = low, j = mid + 1;
        while (i <= mid && j <= high) {
            if (nums[i] > 2LL * nums[j]) {
                count += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }
        return count;
    }

    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid + 1;
        
        // Merge the two sorted halves
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Copy the remaining elements from the left half
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Copy the remaining elements from the right half
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy the merged elements back into the original array
        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }

    int mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return 0;

        int count = 0;
        int mid = low + (high - low) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
