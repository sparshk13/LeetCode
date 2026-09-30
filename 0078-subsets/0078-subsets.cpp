class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int>& nums, vector<int> curr) {
        // base case
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // take
        curr.push_back(nums[index]);
        solve(index + 1, ans, nums, curr);
        curr.pop_back(); // backtracking

        // dont take
        solve(index + 1, ans, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, ans, nums, curr);
        return ans;
    }
};