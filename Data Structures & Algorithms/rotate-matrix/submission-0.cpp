class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // percorre as camadas
        for (int row = 0; row < n / 2; row++) {
            for (int col = row; col < n - row - 1; col++) {

                // salva o elemento do topo
                int temp = matrix[row][col];

                // esquerda -> topo
                matrix[row][col] = matrix[n - 1 - col][row];

                // baixo -> esquerda
                matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col];

                // direita -> baixo
                matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];

                // topo (temp) -> direita
                matrix[col][n - 1 - row] = temp;
            }
        }
    }
};
