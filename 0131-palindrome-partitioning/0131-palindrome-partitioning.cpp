class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int e = s.size() - 1;

        while (st <= e) {
            if (s[st++] != s[e--]) return false;
        }
        return true;
    }

    void solve(string s, vector<vector<string>> &ans, vector<string> &temp, int index) {
        // base case
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string p = s.substr(index, i - index + 1);

            if (isPalindrome(p)) {
                temp.push_back(p);
                solve(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp, 0);
        return ans;
    }
};