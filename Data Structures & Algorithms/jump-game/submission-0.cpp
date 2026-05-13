class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        int l = 0;
        int r = nums.size() - 1;
        int reach = 0;

        while (l <= reach) {
            reach = max(reach, l + nums[l]);

            if (reach >= r) {
                return true;
            }

            l++;
        }

        return false;
    }
};