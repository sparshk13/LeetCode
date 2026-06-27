class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        string ans;
        int i = 0;

        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            word = "";
            while (i < s.length() && s[i] != ' ') {
                word += s[i++];
            }
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if(i) {
                ans += " ";
            }
        }
        return ans;
    }
};