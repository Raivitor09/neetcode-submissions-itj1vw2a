class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path); // the program reads the string piece by piece using a stream
        string part;

        stack<string> st;
        while(getline(ss, part, '/')) {
            if(part == "" || part == ".") {
                continue;
            } else if(part == "..") {
                if(!st.empty()) st.pop();
            } else {
                st.push(part);
            }
        }

        stack<string> st2;
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        string newPath= "/";
        while(!st2.empty()) {
            newPath+=st2.top();
            st2.pop();
            if(!st2.empty()) {
                newPath+="/";
            }
        }

        return newPath;
    }
};

// path = "/neetcode/practice//...///../courses"
// getline(ss, part, '/') => ["","neetcode","","practice","","...","","..","","courses"]

