class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxArea = 0;

        while (l <= r) {
            int width = abs(l - r);
            int height = min(heights[l], heights[r]);
            int area = width * height;

            maxArea = max(maxArea, area);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxArea;
    }
};
