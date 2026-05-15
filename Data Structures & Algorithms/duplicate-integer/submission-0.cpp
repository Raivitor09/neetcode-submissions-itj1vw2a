class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> dup;

        for(int times : nums) {
            dup[times]++;
        }

        return dup[1] != 1;
    }
};
