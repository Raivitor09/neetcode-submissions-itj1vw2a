class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        // unordered_set<char> setS(s.begin(), s.end());
        // unordered_set<char> setT(t.begin(), t.end());

        return s == t;
    }
};
