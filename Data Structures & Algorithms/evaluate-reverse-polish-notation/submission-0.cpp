class Solution {
    bool isNumber(string value) {
        if (value == "+" || value == "/" || value == "*" || value == "-") {
            return false;
        }

        return true;
    }

    void sumTokens(stack<int> &s) {
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();
        s.push(firstTop + secondTop);
    }

    void subTokens(stack<int> &s) {
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();
        s.push(secondTop - firstTop);
    } 

    void timesTokens(stack<int> &s) {
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();
        s.push(firstTop * secondTop);
    }

    void divideTokens(stack<int> &s) {
        int firstTop = s.top(); // 132
        s.pop();
        int secondTop = s.top();
        s.pop();
        s.push(secondTop / firstTop);
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s; // most recent number

        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i])) {
                s.push(stoi(tokens[i]));
            } else if (tokens[i] == "+") {
                sumTokens(s);
            } else if (tokens[i] == "-") {
                subTokens(s);
            } else if (tokens[i] == "*") {
                timesTokens(s);
            } else if (tokens[i] == "/") {
                divideTokens(s);
            }
        }

        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }

        return sum;
    }
    
};
