class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix[0].size() - 1;
        int row = 0;

        while (row < matrix.size()) {
            if (target <= matrix[row][r] && target >= matrix[row][l]) {
                while (l <= r) {
                    int mid = ((int)l + r) / 2;

                    if (target == matrix[row][mid])
                        return true;

                    if (target > matrix[row][mid]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                return false;
            } else {
                row++;
                l = 0, r = matrix[0].size() - 1;
            }
        }

        return false;
    }
};