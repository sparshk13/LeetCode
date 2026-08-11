class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        vector<int> ans;

        if (m > n) {
            return ans;
        }
        
        for (auto ch: p) {
            need[ch - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }

        if (window == need) {
            ans.push_back(0);
        }

        for (int i = 1; i <= n-m; i++) {
            window[s[i-1] - 'a']--;
            window[s[i+m-1] - 'a']++;

            if (window == need) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};