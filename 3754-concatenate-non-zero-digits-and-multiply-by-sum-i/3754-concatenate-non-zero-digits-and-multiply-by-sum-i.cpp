class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        int factor = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                x = digit * factor + x;
                factor *= 10;
                sum += digit;
            }
            n /= 10;
        }
        return sum * x;
    }
};