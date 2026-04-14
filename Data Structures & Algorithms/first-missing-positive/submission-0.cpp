class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1; // the smallest possible positive number- like a default value

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && missing == nums[i]) {
                missing++;
            }
        }

        return missing;
    }
};