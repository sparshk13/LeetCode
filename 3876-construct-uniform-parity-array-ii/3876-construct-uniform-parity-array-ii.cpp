class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = INT_MAX;
        int even = INT_MAX;

        for (auto num: nums1) {
            if (num % 2 != 0) {
                odd = min(num, odd);
            }
            if (num % 2 == 0) {
                even = min(num, even);
            }
        }

        if (odd == INT_MAX) {
            return true;
        }

        return odd < even;
    }
};