class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_set<char> no_dup;
        int l = 0, r = l;
        int currSize = 0, maxSize = 0;

        while(r < s.size()) {
            if(!no_dup.count(s[r]) && (int)no_dup.size() < k) {
                no_dup.insert(s[r]);
                r++;
                currSize = r - l + 1;
            } else if(!no_dup.count(s[r]) && (int)no_dup.size() == k) {
                no_dup.erase(s[l]);
                maxSize = max(currSize, (r - l + 1) - 1);
                l++;
                r = l;
            } else {
                r++;
            }
        }

        return maxSize;
    }
};
