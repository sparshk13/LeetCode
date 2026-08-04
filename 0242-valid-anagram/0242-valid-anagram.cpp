class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        int n = s.size();

        if (s.size() != t.size()) return false;
        
        for (char ch: s) {
            count[ch - 'a'] ++;
        }
        
        for (char ch: t) {
            if (count[ch - 'a'] == 0) {
                return false;
            }
            count[ch - 'a'] --;
        }
        
        return true;
    }
};