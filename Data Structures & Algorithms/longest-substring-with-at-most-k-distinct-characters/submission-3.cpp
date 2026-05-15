class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int, int> charFreq;
        int left = 0, right = left;
        int maxSize = 0;

        for(right = 0; r < s.size(); r++) {
            charFreq[s[r]]++;

            while(charFreq.size() > k) {
                charFreq[s[l]]--;
                if(charFreq[s[l]] == 0) {
                    charFreq.erase(s[l]);
                }
                left++;
            }

            maxSize = max(maxSize, r - l + 1);
        }

        return maxSize;
    }
};
