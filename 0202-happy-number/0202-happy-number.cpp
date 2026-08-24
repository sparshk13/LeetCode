class Solution {
public:
    int next(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));

        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};