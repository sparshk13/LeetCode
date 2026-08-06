class Solution {
public:
    int product(int n) {
        int ans = 1;
        while(n) {
            ans = ans * (n%10);
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        if (product(n) % t == 0) {
            return n;
        }
        return (smallestNumber(n+1, t));
    }
};