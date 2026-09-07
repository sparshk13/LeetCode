class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = n - 1;
        int j = m - 1;
        int k = m + n - 1;
        double median;
        vector<int> ans (m+n);

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                ans[k--] = nums1[i--];
            }
            else {
                ans[k--] = nums2[j--];
            }
        }
        while (i >= 0) {
            ans[k--] = nums1[i--];
        }
        while (j >= 0) {
            ans[k--] = nums2[j--];
        }

        if ((m + n) % 2 == 0) {
            median = ((double)ans[(m+n)/2] + ans[(m+n)/2 - 1]) / 2.0;
        }
        else {
            median = ans[(m+n)/2];
        }
        return median;
    }
};