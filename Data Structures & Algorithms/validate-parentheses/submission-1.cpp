class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            stack.push(s[i]);
        }
        
        vector<char> res;

        while(!stack.empty()) {
            char topS = stack.top();
            stack.pop();
            res.push_back(topS);
        }

        int left = 0;
        int right = s.size() - 1;

        while (left < res.size() && right >= 0) {
            if (res[left] == s[right]) {
                left++;
                right--;
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};
