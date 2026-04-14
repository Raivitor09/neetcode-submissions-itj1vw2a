class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char, int> freqT;
        for(int i = 0; i < t.size(); i++) {
            freqT[t[i]]++;
        }

        unordered_map<char, int> freqS;
        int have = 0, need = freqT.size();
        int minSize = INT_MAX;
        int l = 0, start = l; 

        for(int r = 0; r < s.size(); r++) {
            freqS[s[r]]++;

            if(freqS[s[r]] == freqT[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < minSize) {
                    minSize = r - l + 1;
                    start = l;
                }

                freqS[s[l]]--;
                if(freqT.count(s[l]) && freqS[s[l]] < freqT[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        if(minSize == INT_MAX) {
            return "";
        } else {
            return s.substr(start, minSize);
        }
    }
};

// s = "OUZODYXAZV", t = "XYZ"

// "OUZODYXAZV"
//        L
//            r

// mapS = {
//     O: 0
//     U: 0
//     Z:1
//     D:0
//     Y:0
//     X:1
//     A:1
//     V:1
// }

// HAVE = 2
// NEED = 3

// MINSIZE = 4
// START = 5

// mapT = {
//     X:1
//     Y:1
//     Z:1
// }
