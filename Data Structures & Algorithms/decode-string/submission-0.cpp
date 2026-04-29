class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string charStr;
        string numStr;

        for(char c: s) {
            if(isdigit(c)) { // is he a number?
                numStr += c;
            } else if (isalpha(c)) { // does it belong to the alphabet:
                charStr += c;
            } else if(c == '[') { // Opening bracket means that it start a new operation
                st.push(charStr);
                st.push(numStr);

                numStr = "";
                charStr = "";
            } else { // is hea closing bracket?
                int times = stoi(st.top());
                st.pop();

                string prev = st.top();
                st.pop();

                string tempStr = "";
                while(times--) {
                    tempStr += charStr;// how many times did the letter appear
                }

                charStr = prev + tempStr;
            }
        }

        return charStr;
    }
};