class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left - (left + right) / 2;

            if (nums[mid] == target) return mid;

            if (nums[left] < nums[right]) { // means that the array is sorted
                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // the array is partial sorted
                if (nums[mid] > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
