class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_set<char> setS(s.begin(), s.end());
        unordered_set<char> setT(t.begin(), t.end());

        return setS == setT;
    }
};
