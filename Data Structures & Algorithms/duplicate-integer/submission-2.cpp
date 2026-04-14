class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> dup;

        for(int times : nums) {
            dup[times]++;
        }

        for (auto& entry: dup) {
            if (entry.second > 1) {
                return true;
            } 
        }

        return false;
    }
};
