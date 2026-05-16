class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> zeroes;
        
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(matrix[r][c] == 0) {
                    zeroes.push_back({r,c});
                }
            }
        }

        for(int i = 0; i < zeroes.size(); i++) {
            int row = zeroes[i].first;
            int col = zeroes[i].second;

            // Fill the Rows
            for(int j = 0; j < cols; j++) {
                matrix[row][j] = 0;
            }

            // Fill the Collumns
            for(int k = 0; k < rows; k++) {
                matrix[k][col] = 0;
            }
        }
    }
};
