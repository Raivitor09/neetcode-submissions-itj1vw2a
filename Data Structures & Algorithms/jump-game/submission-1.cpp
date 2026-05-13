class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        int l = 0, r = nums.size() - 1;
        int maxReachableIdx = 0;

        while(l <= maxReachableIdx) {
            maxReachableIdx = max(maxReachableIdx, l + nums[l]);

            if(maxReachableIdx >= r) {
                return true;
            }

            l++;
        }

        return false;
    }
};