class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        vector<int> ans;

        while (l < n && nums[l] < 0) {
            l++;
        }
        int r = l;
        l--;

        while (l >= 0 && r < n) {
            if (abs(nums[l]) <= abs(nums[r])) {
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
            else {
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }

        while (l >= 0) {
            ans.push_back(nums[l] * nums[l]);
            l--;
        }
        while (r < n) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }
        return ans;
    }
};