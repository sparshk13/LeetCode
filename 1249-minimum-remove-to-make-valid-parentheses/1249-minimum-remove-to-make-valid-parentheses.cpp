class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = s;
        int removed = 0;
        int cnt = 0; 
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == '(') {
                cnt++;
            }
            else if (temp[i] == ')') {
                cnt--;
            }
            if (cnt < 0) {
                cnt = 0;
                s.erase(s.begin() + i - removed);
                removed++;
            }
        }
        string a = s;
        cnt = 0;

        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == '(') {
                cnt--;
            }
            else if (a[i] == ')') {
                cnt++;
            }
            if (cnt < 0) {
                cnt = 0;
                s.erase(s.begin() + i);
                removed++;
            }
        }
        return s;
    }
};