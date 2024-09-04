class Solution {
public:
    void mergeTwoArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointing the end of the  nums1
        int j = n - 1; // Pointing the end of the  nums2
        int k = m + n - 1; // total length of the final array of nums1

        // Merge the two arrays and store it into nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums1
        while (i >= 0) {
            nums1[k--] = nums1[i--];
        }

        // If there are remaining elements in nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Time Complexity: O(m+1)
// Space Complexity: O(1)
