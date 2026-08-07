class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
    
        unordered_map<string, vector<string>> sorted;
        
        for (auto str: strs) {
            string original = str;
            sort(str.begin(), str.end());
            sorted[str].push_back(original);
        }
        for (auto it: sorted) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};