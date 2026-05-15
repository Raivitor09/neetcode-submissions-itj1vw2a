class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TRAVERSE THE ROWS IN THE MATRIX
        for(int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;

                if(seen.count(board[row][col])) return false;

                seen.insert(board[row][col]);
            }
        }

        // TRAVERSE THE COLLUMNS IN THE MATRIX
        for(int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for(int row = 0; row < 9; row++) {
                if(board[row][col] == '.') continue;

                if(seen.count(board[row][col])) return false;

                seen.insert(board[row][col]);
            }
        }
        
        // TRAVERSE THE BOXES 3x3
        for(int row = 0; row < 9; row+=3) {
            for(int col = 0; col < 9; col+=3) {
                unordered_set<char> seen;

                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(board[row+i][col+j] == '.') continue;

                        if(seen.count(board[row+i][col+j])) return false;

                        seen.insert(board[row+i][col+j]);
                    }
                }
            }
        }

        return true;
    }
};