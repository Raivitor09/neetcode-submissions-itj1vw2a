class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty() || height.size() < 3) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        // Water at any position depends on the shorter wall 
        // between the left and right sides.
        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] > leftMax) { 
// we could not store water if 
// the current height is greater than maximum Height, 
// because we limit how much water we could store by the shorter height, if not the water runs down
                    leftMax = height[l];
                } else { // it means we could store water
                    res += leftMax - height[l];
                }
                l++;
            } else {
                if(height[r] > rightMax) {
                    rightMax = height[r];
                } else {
                    res += rightMax - height[r];
                }
                r--;
            }
        }

        return res;
    }
};