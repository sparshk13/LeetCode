class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
    
        unordered_map<string, vector<string>> map;
        
        for (auto str: strs) {
            vector<int> count(26, 0);
            
            for (auto ch: str) {
                count[ch-'a']++;
            }
            string key;
            
            for (auto num: count) {
                key += to_string(num) + '#';
            }
            map[key].push_back(str);
        }
        for (auto it: map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};