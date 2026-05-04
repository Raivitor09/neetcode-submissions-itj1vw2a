class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        stack<int> st;
        int maxArea = 0, width, height;

        for(int i = 0; i <  heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                height = heights[st.top()];
                st.pop();

                int rightLimit = i;
                if(st.empty()) {
                    width = rightLimit;
                } else {
                    int leftLimit = st.top();
                    width = rightLimit - leftLimit - 1;
                } 

                int area = height * width;
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }

        return maxArea;
    }
};