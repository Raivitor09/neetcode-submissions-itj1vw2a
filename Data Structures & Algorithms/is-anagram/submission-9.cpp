class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_set<char> setS;
        unordered_set<char> setT;

        for(int i = 0; i < s.size(); i++) {
            if (!setS.count(s[i])) {
                setS.insert(s[i]);
            } else {
                continue;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (!setT.count(t[i])) {
                setT.insert(t[i]);
            } else {
                continue;
            }
        }

        return setS == setT;
    }
};
