class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>, unordered_set<char>> boxes;

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {

                char val = board[r][c];

                if(val == '.') continue;

                pair<int,int> box = {r / 3, c / 3};

                if(
                    rows[r].count(val) ||
                    cols[c].count(val) ||
                    boxes[box].count(val)
                ) {
                    return false;
                }

                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box].insert(val);
            }
        }

        return true;
    }
};