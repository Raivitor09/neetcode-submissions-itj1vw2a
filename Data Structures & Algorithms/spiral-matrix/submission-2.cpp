class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        // Boundaries
        int left = 0, right = cols - 1;
        int top = 0, bottom = rows - 1;

        vector<int> res;
        while(left <= right && top <= bottom) {
            // LEFT -> RIGHT
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // TOP
            //  |
            //  BOTTOM
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // CHECK IF LEFT > RIGHT || TOP > BOTTOM
            // Ainda existe uma submatriz válida para continuar?
            if(left > right || top > bottom) break;

            // LEFT <- RIGHT
            for(int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            //  TOP
            //   ^ 
            //   |
            // BOTTOM
            for(int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};