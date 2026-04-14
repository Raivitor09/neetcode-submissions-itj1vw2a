class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> charFreq;
        int l = 0, r = 0;
        int maxLen = 0;

        for(r = 0; r < s.size(); r++) {
            charFreq[s[r]]++;

            while(charFreq.size() > k) {
                charFreq[s[l]]--;
                if(charFreq[s[l]] == 0) {
                    charFreq.erase(s[l]);
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
//  s = "eceba", k = 2
//          l
//            r

// map = {
//     b:1
//     a:1
// }

// maxLen = 3