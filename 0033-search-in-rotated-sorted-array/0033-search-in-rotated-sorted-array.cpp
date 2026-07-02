class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        
        while (s<=e) {
            int mid = s + (e-s)/2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[s] <= nums[mid]) {
                // left half is sorted
                if (target >= nums[s] && target < nums[mid]) {
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
            else if (nums[e] > nums[mid]) {
                //  right half is sorted
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            }

        }
        return -1;
    }
};