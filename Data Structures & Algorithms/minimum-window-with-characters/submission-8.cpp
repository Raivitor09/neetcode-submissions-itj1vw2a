class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT;
        for(int i = 0; i < t.size(); i++) {
            mapT[t[i]]++;
        }
        // {
        //     X:1
        //     Y:1
        //     Z:1
        // }

        unordered_map<char, int> mapWindow;
        int windowLen = INT_MAX, start = -1;
        int have = 0, need = mapT.size();
        int l = 0, r = l;

        for(r = 0; r < s.size(); r++) {
            mapWindow[s[r]]++;

            if(mapT.count(s[r]) && mapWindow[s[r]] == mapT[s[r]]) {
                have++;
            }

            while(have == need) {
                if(windowLen > r - l + 1) {
                    windowLen = r - l + 1;
                    start = l;
                }

                mapWindow[s[l]]--;
                if(mapT.count(s[l]) && mapWindow[s[l]] < mapT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (windowLen == INT_MAX) {
            return "";
        } else {
            return s.substr(start, windowLen);
        }
    }
};

//  s = "OUZODYXAZV", t = "XYZ"

//  mapWindow = {                          
//     o:0
//     u:0
//     z:1
//     d:0
//     y:0
//     x:1
//     a:1
//     v:1
//  }

//  mapT{
//     x:1
//     y:1
//     z:1
//  }

//  have = 3
//  need = 3

//  windowLen = 4
//  start = 5
