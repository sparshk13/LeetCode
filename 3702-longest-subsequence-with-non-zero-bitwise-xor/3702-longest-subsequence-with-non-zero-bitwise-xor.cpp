class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        bool nonzero = false;

        for (auto num: nums) {
            temp ^= num;

            if (num != 0) {
                nonzero = true;
            }
        }
        if (temp != 0) {
            return n;
        }
        if (nonzero) {
            return n-1;
        }
        return 0;
    }
};