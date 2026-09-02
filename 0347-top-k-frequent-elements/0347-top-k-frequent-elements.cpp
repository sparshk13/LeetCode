class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // num, freq
        vector<int> result;

        for (auto num: nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto it: count) {
            pq.push({it.second, it.first});
        }

        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};