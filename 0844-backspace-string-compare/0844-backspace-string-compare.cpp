class Solution {
public:
    int clean(string& str) {
        int k = 0;

        for (auto ch: str) {
            if (ch != '#') {
                str[k++] = ch;
            }
            else if (k > 0) {
                k--;
            }
        }
        return k;
    }

    bool backspaceCompare(string s, string t) {
        int a = clean(s);
        int b = clean(t);

        if (a != b) return false;

        for (int i = 0; i < a; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};