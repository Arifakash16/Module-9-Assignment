class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { 
        quickSort(nums, 0, nums.size() - 1);    // Sort the array using QuickSort
        return nums[nums.size() - k];   // Return the k-th largest element
    }

    void quickSort(vector<int>& nums, int left, int right) {  // apply quicksort logic
        if (left < right) {
            int pivotIndex = partition(nums, left, right);
            quickSort(nums, left, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivotValue = nums[right];     // Choosing the rightmost element as the pivot
        int storeIndex = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] > pivotValue) 
            {                                   // For descending order sorting
                swap(nums[i], nums[storeIndex]);
                ++storeIndex;
            }
        }
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
// QuickSort is best fit for this problem because of its average 𝑂(𝑛log𝑛) time complexity
// and efficient in-place sorting, which minimize the additional space usage. 