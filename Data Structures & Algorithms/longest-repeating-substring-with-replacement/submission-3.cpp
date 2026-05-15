class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqS;

        for(int i = 0; i < s.size(); i++) {
            freqS[s[i]]++;
        }
        
        int maxFreq = 0;
        for(auto& character: freqS) {
            maxFreq = max(maxFreq, character.second);
        }

        if(freqS.size() == 1) return maxFreq;
        return maxFreq + k;
    }
};
