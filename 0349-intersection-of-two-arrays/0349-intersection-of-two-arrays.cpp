class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> seen (1001, 0);
        vector<int> ans;

        for (auto num: nums1) {
            seen[num] = true;
        }

        for (auto num: nums2) {
            if (seen[num]) {
                ans.push_back(num);
                seen[num] = false;
            }
        }
        return ans;
    }
};