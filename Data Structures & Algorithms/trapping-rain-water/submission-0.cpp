class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        for(int i = 0; i < n; i++) {
            int maxLeft = 0, maxRight = 0;

            for(int l = 0; l <= i; l++) {
                maxLeft = max(height[l], maxLeft);
            }
            for(int r = n - 1; r >= i; r--) {
                maxRight = max(height[r], maxRight);
            }

            int level = min(maxLeft, maxRight);
            
            if(level > height[i]) {
                totalWater += level - height[i];
            }
        }

        return totalWater;
    }
};
