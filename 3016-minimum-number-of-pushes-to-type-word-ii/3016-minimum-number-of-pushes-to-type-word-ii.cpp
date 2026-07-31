class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[word[i] - 'a']++;
        }
        sort(count.rbegin(), count.rend());

        int temp = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) break;

            ans += count[i] * (i/8+1);
        }

        return ans;
    }
};