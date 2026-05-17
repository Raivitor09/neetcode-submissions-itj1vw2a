class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            unordered_set<char> rowSeen;
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == '.') continue;

                if(rowSeen.count(board[r][c])) return false;

                rowSeen.insert(board[r][c]);
            }
        }

        for(int c = 0; c < cols; c++) {
            unordered_set<char> colSeen;
            for(int r = 0; r < rows; r++) {
                if(board[r][c] == '.') continue;

                if(colSeen.count(board[r][c])) return false;

                colSeen.insert(board[r][c]);
            }
        }

        for(int r = 0; r < rows; r+=3) {
            for(int c = 0; c < cols; c+=3) {
                unordered_set<char> boxSeen;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(board[r+i][c+j] == '.') continue;

                        if(boxSeen.count(board[r+i][c+j])) return false;

                        boxSeen.insert(board[r+i][c+j]);
                    }
                }
            }
        }

        return true;
    }
};