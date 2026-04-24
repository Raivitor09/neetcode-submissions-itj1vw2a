class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/')) {
            if(part == "." || part == "") {
                continue;
            } else if(part == "..") {
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(part);
            }
        }
        
        if(st.empty()) return "/";

        vector<string> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        string ans;
        for(string& s : res) {
            ans+= "/" + s;
        }

        return ans;
    }
};

// "/neetcode/practice//...///../courses"

// part ["", "neetcode", "", "practice", "", "", ]

// stringstream ss(path)

// Turns the string into a stream so you can read it piece by piece, like a cursor moving through the string.
// ---
// string part

// Stores the current piece (directory or command) extracted from the path.
// ---
// getline(ss, part, '/')

// Reads characters from ss until it finds '/', and stores that piece in string part.
// It skips the '/' and continues from the next position.