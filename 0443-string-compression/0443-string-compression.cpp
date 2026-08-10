class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        string ans;

        while (i < n) {
            int j = i;
            int count = 0;
            while (j < n && chars[j] == chars[i]) {
                count ++;
                j++;
            }
            ans += chars[i];
            if (count > 1) {
                ans += to_string(count);
            }
            i = j;
        }

        for (int k = 0; k < ans.size(); k++) {
            chars[k] = ans[k];
        }
        
        return ans.size();
    }
};