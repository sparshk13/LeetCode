class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count; // num, freq
        for (auto num: nums) {
            count[num]++;
        }

        vector<vector<int>> bucket(n+1);
        vector<int> ans;

        for (auto[num, freq]: count) {
            bucket[freq].push_back(num);
        }

        for (int i = n; i >= 1; i--) {
            for (auto num: bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};