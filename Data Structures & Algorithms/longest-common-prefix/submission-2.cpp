class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());
        
        string first = strs.front();
        string last = strs.back();

        string res;

        for(int i = 0; i < first.size(); i++) {
            if(first[i] != last[i]) {
                break;
            } else {
                res += first[i]; // += last[i], as long as they are equal doesn't matter
            }
        }

        return res;
    }
};