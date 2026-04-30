class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closingToOpening = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> st;

        for(char c: s) {
            if (!closingToOpening[c]){
                st.push(c);
            } else {
                if(st.empty()) {
                    return false;
                } else {
                    if(st.top() == closingToOpening[c]) {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        if(!st.empty()) {
            return false;
        } else {
            return true;
        }

    }
};

// s = "([{}])"

// st = ([{
