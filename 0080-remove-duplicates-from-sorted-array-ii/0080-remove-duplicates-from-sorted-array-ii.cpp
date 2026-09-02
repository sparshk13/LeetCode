class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 2;

        if (n < 2) {
            return n;
        }

        for (int r = 2; r < n; r++){
            if (nums[r] != nums[l-2]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};