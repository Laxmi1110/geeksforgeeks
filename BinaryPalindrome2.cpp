class Solution {
public:
    bool isBinaryPalindrome(int n) {
        int left = 31;
        int right = 0;

        // Find MSB
        while (left > 0 && ((n >> left) & 1) == 0) {
            left--;
        }

        // Compare bits
        while (left > right) {
            int lbit = (n >> left) & 1;
            int rbit = (n >> right) & 1;

            if (lbit != rbit) return false;

            left--;
            right++;
        }

        return true;
    }
};
