class Solution {
public:
    int check(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false;
            }

            seen.insert(n);
            n = check(n);
        }

        return true;
    }
};