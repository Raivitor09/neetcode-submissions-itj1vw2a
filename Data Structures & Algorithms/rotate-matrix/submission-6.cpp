class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // TRANSPOSE -> ROW becomes COL
        for(int row = 0; row < n; row++) {
            for(int col = row + 1; col < n; col++) { // Porque assim você só troca os elementos acima da diagonal principal.
                swap(matrix[row][col], matrix[col][row]);;
            }
        }

        // REFLECT-> CHANGE TEH VALUES, ROWS BY ROWS
        for(int row = 0; row < n; row++) {
            for(int left = 0, right = n - 1; left < right; left++, right--) {
                swap(matrix[row][left], matrix[row][right]);
            }
        }
    }
};