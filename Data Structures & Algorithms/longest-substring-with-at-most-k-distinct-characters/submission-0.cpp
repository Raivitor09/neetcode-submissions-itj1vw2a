class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_set<char> no_dup_string;
        int maxSize = 0;
        int l = 0, r = l;

        while(r < s.size()) {
            if(!no_dup_string.count(s[r])) {
                no_dup_string.insert(s[r]);
                maxSize = max(maxSize, (int) no_dup_string.size());
                r++;
            } else {
                no_dup_string.erase(s[l]);
                l++;
            }
        }

        return maxSize;
    }
};
