class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        if (nums.empty()) {
            return 0;
        }

        for (auto num: st) {
            if (st.find(num - 1) == st.end()) {
                int temp = num;
                int length = 1;

                while (st.find(temp+1) != st.end()) {
                    length++;
                    temp++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};