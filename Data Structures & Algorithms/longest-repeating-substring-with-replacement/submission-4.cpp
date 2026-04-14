class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charFreq;
        int maxSize = 0, left = 0;
        int maxCharFreq = 0;

        for(int right = 0; right < s.size(); right++) {
            charFreq[s[right]]++;
            maxCharFreq = max(maxCharFreq, charFreq[s[right]]);

            while((right - left + 1) - maxCharFreq > k) { // Shrink the window
                charFreq[s[left]]--;
                left++;
            }

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};
