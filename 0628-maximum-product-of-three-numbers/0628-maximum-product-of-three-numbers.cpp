class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long max1 = INT_MIN;
        long long max2 = INT_MIN;
        long long max3 = INT_MIN;
        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for (auto num: nums) {
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        long long ans1 = max1 * max2 * max3;
        long long ans2 = max1 * min1 * min2;
        return max(ans1, ans2);
    }
};