class Solution {
public:
    int maxArea(vector<int>& heights) {
        int currArea = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int width = abs(left - right);

            int height = min(heights[left], heights[right]);

            int area = width * height;

            currArea = max(area, currArea);

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }

        return currArea;
    }
};
