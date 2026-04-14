class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int sum = target - nums[i];

            if (index.find(sum) != index.end() && i < index[sum]) {
                return {i, index[sum]};
            }
        }
    }
};
