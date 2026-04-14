class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for (int i = 0; i < s.size(); i++) { // they have the same space, so doesn't matter if we iterate the s.size or t.size
            mapS[s[i]]++; 
            // J:1
            // a:1
            // r:1 
            mapT[t[i]]++; 
            // J:1
            // a:1
            // m:1
        }

        return mapS == mapT;
    }
};
