class Solution {
public:
    int len(int n) {
        int cnt = 0;
        while (n > 0) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        int lowlen = len(low);
        int highlen = len(high);

        vector<int> ans;

        for (int len = lowlen; len <= highlen; len++) {
            for (int i = 0; i < 9-len+1; i++) {
                int num = stoi(s.substr(i, len));
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};