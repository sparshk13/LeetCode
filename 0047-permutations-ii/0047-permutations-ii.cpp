class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<bool>& used, vector<int>& temp, vector<int>& nums) {

        // base case 
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // skip duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // choosing
            temp.push_back(nums[i]);
            used[i] = true;

            // recursive call
            solve(ans, used, temp, nums);

            // backtracking
            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> temp;

        solve(ans, used, temp, nums);

        return ans;
    }
};