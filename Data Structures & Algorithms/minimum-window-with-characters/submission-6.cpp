class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        if(s == t) return s;

        unordered_map<int, int> countT;
        for(int i = 0; i < t.size(); i++) {
            countT[t[i]]++;
        }
        unordered_map<int, int> window;

        int have = 0, need = countT.size();
        int resL = -1;
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while(have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    resL = l;
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (resLen == INT_MAX) {
            return "";
        } else {
            return s.substr(resL, resLen);
        }
    }
};
