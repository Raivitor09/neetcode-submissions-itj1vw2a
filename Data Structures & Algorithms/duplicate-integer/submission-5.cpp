class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> frequencies;

        for (auto& freq : nums) {
            frequencies[freq]++;
        }

        for (auto& checkDup : frequencies) {
            int value = checkDup.second;

            if (value > 1) {
                return true;
            }
        }

        return false;
    }
};
