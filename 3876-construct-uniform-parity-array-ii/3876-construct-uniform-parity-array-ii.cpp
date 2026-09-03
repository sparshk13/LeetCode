class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = INT_MAX;

        for (auto num: nums1) {
            if (num % 2 != 0) {
                mini = min(num, mini);
            }
        }

        if (mini == INT_MAX) {
            return true;
        }

        for (auto num: nums1) {
            if (num % 2 == 0 && num < mini) {
                return false;
            }
        }
        return true;
    }
};