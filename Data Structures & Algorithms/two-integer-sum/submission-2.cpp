class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int sum = target - nums[i];

            if (index.count(sum) > 0 && i < index[sum]) { // VERIFY IF THE KEY EXISTS
                return {i, index[sum]};
            }
        }
    }
};
