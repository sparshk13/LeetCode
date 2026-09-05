class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(nums);

        for (int i = n-2; i >= 0; i--) {
            mini[i] = min(nums[i], mini[i+1]);
        }

        int maxi = nums[0];
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
            if (maxi - mini[i] <= k) {
                return i;
            } 
        }
        return -1;
    }
};