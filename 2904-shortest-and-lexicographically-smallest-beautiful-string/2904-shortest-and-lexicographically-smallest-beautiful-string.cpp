class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans;
        int len = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = i; j < n; j++) {
                int temp = j-i+1;
                
                if (s[j] == '1') {
                    count++;
                }
                if (count == k) {
                    string curr = s.substr(i, temp);
                    
                    if (temp < len) {
                        ans = curr;
                        len = temp;
                    }
                    else if (temp == len && curr < ans) {
                        ans = curr;
                    }
                    break;
                }
                if (count > k) {
                    break;
                }
            }
        }
        return ans;
    }
};