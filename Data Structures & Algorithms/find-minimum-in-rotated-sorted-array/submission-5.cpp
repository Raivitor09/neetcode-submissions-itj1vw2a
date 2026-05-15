class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        
        if (nums.size() == 1) {
            return nums[left];
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[left] <= nums[right]) {
                return nums[left];
            } else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                return nums[mid];
            } else {
                left = mid + 1;
                continue;
            }
        } 
    }
};
