class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int min = nums[0];
        int max = nums[nums.size() - 1];

        vector<int> ans;

        int i = min;

        while (i <= max) {
            if (find(nums.begin(), nums.end(), i) != nums.end()) {
                i++;
            }
            else {
                ans.push_back(i);
                i++;
            }
        }

        return ans;
    }
};