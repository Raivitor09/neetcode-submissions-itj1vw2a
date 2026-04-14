class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int rev = 0;
        int temp_x = x;
        while (temp_x > 0) {
            rev = rev * 10 + (temp_x % 10);
            temp_x /= 10;
        }

        if (rev == x) {
            return true;
        } else {
            return false;
        }
    }
};