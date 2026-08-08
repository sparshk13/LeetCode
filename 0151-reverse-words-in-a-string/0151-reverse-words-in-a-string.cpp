class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;
        
        for (int i = 0; i < s.size(); i++) {
            string temp;
            while (i < s.size() && s[i] != ' ') {
                temp.push_back((s[i]));
                i++;
            }
            if (!temp.empty()) 
                st.push(temp);
        }
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();

            if (!st.empty()) {
                ans += " ";
            }
        }
        return ans;
    }
};