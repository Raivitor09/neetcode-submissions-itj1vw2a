class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                return nums[mid];
            } else if(nums[left] < nums[right] || nums[right] == nums[left]) {
                return nums[left];
            } else {
                left = mid + 1;
                continue;
            }
        } 
    }
};
