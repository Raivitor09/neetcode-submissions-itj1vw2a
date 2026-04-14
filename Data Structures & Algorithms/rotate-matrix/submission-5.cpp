class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose => Rows become Columns
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reflect => Change the elements row by row
        for(int row = 0; row < n; row++) {
            int left = 0, right = n - 1;

            while(left < right) {
                swap(matrix[row][left], matrix[row][right]);
                left++, right--;
            }
        }
    }
};
