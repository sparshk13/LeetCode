 class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<bool> ans;
        int oneinS = 0;
        vector<int> prefixS(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                oneinS++;
            prefixS[i] = oneinS;
        }

        for (auto str : strs) {

            int oneinStr = 0;
            vector<int> questionMark;

            for (int i = 0; i < n; i++) {
                if (str[i] == '1')
                    oneinStr++;
                else if (str[i] == '?')
                    questionMark.push_back(i);
            }

            int requiredOnes = oneinS - oneinStr;

            if (requiredOnes < 0 || requiredOnes > questionMark.size()) {
                ans.push_back(false);
                continue;
            }

            for (int index : questionMark)
                str[index] = '0';

            for (int i = (int)questionMark.size() - 1;
                 i >= (int)questionMark.size() - requiredOnes;
                 i--) {
                str[questionMark[i]] = '1';
            }

            int currentPrefixOnes = 0;
            bool possible = true;

            for (int i = 0; i < n; i++) {
                if (str[i] == '1')
                    currentPrefixOnes++;

                if (currentPrefixOnes > prefixS[i]) {
                    possible = false;
                    break;
                }
            }

            ans.push_back(possible);
        }

        return ans;
    }
};