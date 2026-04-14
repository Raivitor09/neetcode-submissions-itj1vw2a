class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if(l == 0 && nums[l] > target) return 0;
            int m = ((int) l + r) / 2;

            if(nums[m] == target) return m;

            if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};