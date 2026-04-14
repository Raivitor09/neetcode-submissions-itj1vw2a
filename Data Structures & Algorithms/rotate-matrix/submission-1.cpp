class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Solving this question using linear algebra- matrix transpose & reflection
        int n = matrix.size();

        // Transpose -> rows become collumns and vice-versa
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Horizontal Reflection -> change the elements, row by row
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
