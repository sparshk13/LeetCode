class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> map;
        int rank = 1;

        for (auto num: temp) {
            if (!map.count(num)) {
                map[num] = rank++;
            }
        }
        for (int &val: arr) {
            val = map[val];
        }
        return arr;
    }
};