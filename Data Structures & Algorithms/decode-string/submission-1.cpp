class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string numStr, charStr;

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                numStr += s[i];
            } else if (isalpha(s[i])) {
                charStr += s[i];
            } else if (s[i] == '[') {
                st.push(charStr);
                st.push(numStr);

                charStr = "";
                numStr = "";
            } else {
                int times = stoi(st.top());
                st.pop();
                string prev = st.top();
                st.pop();

                string temp;
                for(int i = 0; i < times; i++) {
                    temp += charStr;
                }

                charStr = prev + temp;
            }
        }

        return charStr;
    }
};