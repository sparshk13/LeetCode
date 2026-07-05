class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map <int, vector<int>> map; // digit range, numbers
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int maxi = 0;
            int mini = 9;
            if(nums[i] == 0) {
                maxi = mini = 0;
            }
            
            while(nums[i] != 0) {
                int digit = nums[i] % 10;
                maxi = max(maxi, digit);
                mini = min(mini, digit);
                nums[i] /= 10;
            }
            int digitRange = maxi - mini;
            map[digitRange].push_back(num);
        }
        for (int i = 9; i >= 0; i--) {
            if (map.find(i) != map.end()) {
                for (auto num: map[i]) {
                    ans += num;
                }
                return ans;
            }
        }
        return 0;
    }
};