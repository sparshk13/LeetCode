class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 0; i < n-1; i++) {
            int a = nums[i];
            int b = nums[i+1];

            for (int x = a+1; x < b; x++) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};