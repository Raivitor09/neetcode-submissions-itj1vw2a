class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix[0].size() - 1;

        for(int row = 0; row < matrix.size(); row++) {
            if(target >= matrix[row][l] && target <= matrix[row][r]) {
                while(l <= r) {
                    int m = ((int) l + r) / 2;

                    if(matrix[row][m] == target) return true;

                    if(target > matrix[row][m]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                break;
            } else {
                continue;
            }
        }

        return false;
    }
};
