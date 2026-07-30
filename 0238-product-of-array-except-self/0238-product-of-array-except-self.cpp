class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int mul = 1;
        // vector<int> answer(nums.size());
        // for (auto num: nums) {
        //     mul *= num;
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     int temp = mul;
        //     if (nums[i] == 0) {
        //         answer[i] = temp;
        //     }
        //     else {
        //         answer[i] = temp / nums[i];
        //     }
        // }
        // return answer;

        int n = nums.size();

        vector<int> answer(n);
        vector<int> pref(n+1);
        vector<int> suff(n+1);
        pref[0] = 1;
        suff[n-1] = 1;

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suff[i] = suff[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            answer[i] = pref[i] * suff[i];
        }
        return answer;
    }
};