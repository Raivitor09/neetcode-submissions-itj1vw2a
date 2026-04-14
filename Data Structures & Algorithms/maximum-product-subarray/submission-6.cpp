class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int currMax = 1, currMin = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            maxProduct = max(maxProduct, currMax);
        }

        return maxProduct;
    }
};