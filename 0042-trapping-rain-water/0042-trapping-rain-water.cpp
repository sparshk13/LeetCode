class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int left = 0, right = 0;
        int ans = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                left = max(height[l], left);
                ans += left - height[l];
                l++;
            }
            else {
                right = max(height[r], right);
                ans += right - height[r];
                r--;
            }
        }
        return ans;
    }
};