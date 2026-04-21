class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                ans[prevIdx] = i - prevIdx;
            }

            st.push(i);
        }

        return ans;
    }
};
