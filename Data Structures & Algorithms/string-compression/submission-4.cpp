class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;

        int i = 0, write = 0;
        while(i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            while(i < chars.size() && currentChar == chars[i]) {
                i++, count++;
            }

            chars[write] = currentChar;
            write++;

            if(count > 1) {
                string countStr = to_string(count);
                for(int i = 0; i < countStr.size(); i++) {
                    chars[write] = countStr[i];
                    write++;
                }
            }
        }

        return write;
    }
};