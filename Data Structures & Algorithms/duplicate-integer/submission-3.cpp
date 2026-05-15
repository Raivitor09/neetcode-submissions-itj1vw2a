class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int> freq;

        for (int freq : nums) {
            freq[nums]++;
        }

        for (int duplicate : freq) {
            int key = duplicate.first;
            int value = duplicate.second;

            if (value > 1) {
                return true;
            }
        }

        return false;
    }
};
