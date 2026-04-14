class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < strs.size(); i++) {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());

            groups[sortedString].push_back(strs[i]);
            // agroup the anagrams
                // the sortedString as a key and the originalString as the value 
        }

        vector<vector<string>> output;

        for (auto& groupAnagrams : groups) {
            // push the values(they are strings) in the vector output
            output.push_back(groupAnagrams.second);
        }

        return output;
    }
};
