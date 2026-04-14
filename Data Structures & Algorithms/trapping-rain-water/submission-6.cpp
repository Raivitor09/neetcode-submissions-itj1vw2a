class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty() || height.size() < 3) return 0;

        int maxLeft = 0, maxRight = 0;
        int area = 0;
        int l = 0, r = height.size() - 1;

        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] > maxLeft) {
                    maxLeft = height[l];
                } else {
                    area += maxLeft - height[l]; 
                }
                l++;
            } else {
                if(height[r] > maxRight) {
                    maxRight = height[r];
                } else {
                    area += maxRight - height[r];
                }
                r--;
            }
        }

        return area;
    }
};
