class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;  // Corrigido de 'stack<int>' para 'stack<char>'

        for (int i = 0; i < s.size(); i++) {
            stack.push(s[i]);
        }
        
        vector<char> res;  // Corrigido de 'vector<string>' para 'vector<char>'

        while (!stack.empty()) {
            char topS = stack.top();
            stack.pop();
            res.push_back(topS);
        }

        int left = 0;
        int right = res.size() - 1;  // Corrigido para comparar corretamente

        while (left < res.size() && right >= 0) {  // Corrigido 'right > s.size()' para 'right >= 0'
            if (res[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }
};
