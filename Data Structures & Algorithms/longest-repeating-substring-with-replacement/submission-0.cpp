class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int right;
        int res = 0; // store the longest string
        int maxF = 0; // store the current max Frequency

        for(right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxF = max(maxF, count[s[right]]);

            while (((right - left + 1) - maxF) > k) { // check if the window is greater than k, if it its we gonna decrement de count[s[l]] and left aswell
                count[s[left]]--;
                left++;
                // keep the window in a good state for replacements
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
