class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = ((long long) left + mid) / 2;

            if(nums[left] < nums[right]) {
                return nums[left];
            } else {
                left = mid + 1;
            }
        } 
    }
};
