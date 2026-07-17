class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        long num = 0;
        while (x > 0) {
            int digit = x%10;
            num = num * 10 + digit;
            x /= 10;
        }
        return (num == temp);
    }
};