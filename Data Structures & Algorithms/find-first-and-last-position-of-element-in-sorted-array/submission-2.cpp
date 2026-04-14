class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int first = -1, last = -1;

        // find the first position
        while(l <= r) {
            int m = ((int) l + r) / 2;

            if(nums[m] == target) {
                first = m;
                r = m - 1;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = ((int) l + r) / 2;

            if(nums[m] == target) {
                last = m;
                l = m + 1;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return {first, last};
    }
};