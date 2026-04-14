class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> stringS;
        unordered_map<char, int> stringT;

        for (char c: s) {
            stringS[c]++;
        }

        for (char c: t) {
            stringT[c]++;
        }

        return stringT == stringS;
    }
};
