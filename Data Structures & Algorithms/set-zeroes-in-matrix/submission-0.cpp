class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        // Find where each zeroes is and insert onto the vector
        vector<pair<int, int>> zeroes;
        for(int r = 0; r < rowSize; r++) {
            for(int c = 0; c < colSize; c++) {
                if(matrix[r][c] == 0) {
                    zeroes.push_back({r, c});
                }
            }
        }

        // Fill the rows and the collumns
        for(int i = 0; i < zeroes.size(); i++) {
            int row = zeroes[i].first;
            int col = zeroes[i].second;

            // Fill the row
            for(int j = 0; j < colSize; j++) {
                matrix[row][j] = 0;
            }

            // Fill the collumns
            for(int k = 0; k < rowSize; k++) {
                matrix[k][col] = 0;
            }
        }
    }
};