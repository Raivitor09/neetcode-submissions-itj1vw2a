class Solution {
public:
    string longestPalindrome(string s) {
        string curr;
        string res;

        for(int i = 0; i < s.size(); i++) {
            // if the palindrome has an odd size
            int left= i, right = i;  

            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                curr = s.substr(left, right - left + 1);
                if(curr.size() > res.size()) {
                    res = curr;
                }
                left--, right++;
            }

            // if the palindrome has an even size
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                curr = s.substr(left, right - left + 1);
                if(curr.size() > res.size()) {
                    res = curr;
                }
                left--, right++;
            }
        }

        return res;
    }
};
