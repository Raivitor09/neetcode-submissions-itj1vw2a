class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Transpose(Swap in the principal diagonal)-> Partially rotated
        for(int r = 0; r < rows; r++) {
            for(int c = r + 1; c < cols; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        // Reflect -> ROW BY ROW
        for(int row = 0; row < rows; row++) {
            for(int l = 0, r = cols - 1; l < r; l++, r--) {
                swap(matrix[row][l], matrix[row][r]);
            }
        }
    }
};
