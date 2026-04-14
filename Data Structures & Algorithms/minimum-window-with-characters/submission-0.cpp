class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> needCount;
        for (char c : t) needCount[c]++;

        int need = t.size();  // total de chars que precisamos
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            // se o char atual ainda é necessário, reduz o "need"
            if (needCount[s[r]] > 0)
                need--;

            needCount[s[r]]--; // sempre decrementa

            // quando need == 0, temos uma janela válida
            while (need == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                needCount[s[l]]++; // devolve o char

                // se este char está faltando novamente, perde validade
                if (needCount[s[l]] > 0)
                    need++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
