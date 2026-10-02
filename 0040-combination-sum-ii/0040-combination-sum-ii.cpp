class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &
    temp, int target, int sum, int index) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                sum += candidates[i];

                solve(candidates, ans, temp, target, sum, i + 1);

                sum -= candidates[i];
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());

        solve(candidates, ans, temp, target, sum, 0);
        return ans;
    }
};