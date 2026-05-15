class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int m = ((int) l + r) / 2;

            if(nums[m] == target) return m;

            if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }

            if(l < 0 || r < 0) {
                return 0;
            }
        }

        return l + 1;
    }
};