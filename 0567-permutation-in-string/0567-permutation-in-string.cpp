class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> arr(26, 0);
        vector<int> check(26, 0);

        for (auto ch: s1) {
            arr[ch - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++) {
            check[s2[i] - 'a']++;
        }

        if (check == arr) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            check[s2[i - s1.size()] - 'a']--;
            check[s2[i] - 'a']++;

            if (check == arr) {
                return true;
            }
        }
        return false;
    }
};