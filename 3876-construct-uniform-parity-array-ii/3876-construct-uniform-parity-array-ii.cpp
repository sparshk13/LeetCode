class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int odd = 0;

        for (auto num: nums1) {
            mini = min(num, mini);
            if (num % 2 != 0) {
                odd++;
            }
        }
        return odd == 0 || mini % 2 != 0;
    }
};