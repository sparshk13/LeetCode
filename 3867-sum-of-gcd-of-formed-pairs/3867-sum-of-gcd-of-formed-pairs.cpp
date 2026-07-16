class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> prefixGcd(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n-1; 
        while (i < j) {
            sum += gcd(prefixGcd[i++], prefixGcd[j--]);
        }
        return sum;
    }
};