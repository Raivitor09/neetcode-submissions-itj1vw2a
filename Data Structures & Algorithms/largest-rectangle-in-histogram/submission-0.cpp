class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, width, height;
        
        // O 0 no final força o cálculo das áreas restantes.
        // Ex: [2,5,6] vira [2,5,6,0], então o 0 processa 6, depois 5, depois 2.
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                height = heights[st.top()];
                st.pop();

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = width * height;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};