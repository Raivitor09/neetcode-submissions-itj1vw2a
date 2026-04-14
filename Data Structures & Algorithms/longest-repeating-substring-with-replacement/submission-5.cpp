class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = left;
        unordered_map<char, int> charFreq;
        int maxCharFreq = 0;
        int maxWindow = 0;

        while(right < s.size()) {
            charFreq[s[right]]++;
            maxCharFreq = max(maxCharFreq, charFreq[s[right]]);

            while (((right - left + 1) - maxCharFreq) > k) {
                charFreq[s[left]]--;
                left++;
            }

            if(right - left + 1 > maxWindow) {
                maxWindow = right - left + 1;
            }
            right++;
        }

        return maxWindow;
    }
};
