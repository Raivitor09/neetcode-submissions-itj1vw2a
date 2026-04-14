class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int currMax = 1, currMin = 1;

        for(int num: nums) {
            int tempMax = currMax * num;
            int tempMin = currMin * num;

            currMax = max(max(tempMax, tempMin), num);
            currMin = min(min(tempMax, tempMin), num);

            maxProd = max(currMax, maxProd);
        }
        
        return maxProd;
    }
};