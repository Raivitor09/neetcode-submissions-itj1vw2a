class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int, int> charFreq;
        int left = 0, right = left;
        int maxSize = 0;

        for(right = 0; right < s.size(); right++) {
            charFreq[s[right]]++;

            while(charFreq.size() > k) {
                charFreq[s[left]]--;
                if(charFreq[s[left]] == 0) {
                    charFreq.erase(s[left]);
                }
                left++;
            }

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};
