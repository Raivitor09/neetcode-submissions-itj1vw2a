class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for (int i = 0; i < s.size(); i++) { // they have the same space, so doesn't matter if we iterate the s.size or t.size
            mapS[s[i]]++; 
            // s[2] = r 
            // mapS[0] = jar
            mapT[t[i]]++; 
            // t[2] = m
            // mapT[0] = jam
        }

        return mapS == mapT;
    }
};
