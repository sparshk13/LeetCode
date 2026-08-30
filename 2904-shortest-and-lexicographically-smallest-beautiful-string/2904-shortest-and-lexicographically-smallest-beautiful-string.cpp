class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> index;
        int l = 0;
        int count = 0;
        string ans;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                index.push_back(i);
            }
        }

        if (index.size() < k) {
            return ans;
        }

        for (int i = 0; i+k-1 < index.size(); i++) {
            int st = index[i];
            int e = index[i+k-1];

            string curr = s.substr(st, e-st+1);

            if (ans == "" ||
                curr.size() < ans.size() ||
                (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
        }
        return ans;
    }
};