class Solution {
public:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &temp, int sum, int index) {
        if (temp.size() == k) {
            if (sum == n) {
                ans.push_back(temp);
            }
            return;
        }
        

            for (int i = index; i <= 9; i++) {
                if (sum + i <= n) {
                    temp.push_back(i);

                    solve(k, n, ans, temp, sum + i, i + 1);

                    temp.pop_back();
                }
            }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(k, n, ans, temp, 0, 1);
        return ans;
    }
};