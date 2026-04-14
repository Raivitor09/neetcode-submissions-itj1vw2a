/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    // Função recursiva para calcular as alturas das subárvores e verificar o balanceamento
    int dfs(TreeNode* root, bool& isBalanced) {
        if (!root) {
            return 0;  // Se o nó for nulo, a altura é 0.
        }

        // Recursão para calcular as alturas das subárvores esquerda e direita
        int leftHeight = dfs(root->left, isBalanced);
        int rightHeight = dfs(root->right, isBalanced);

        // Verifica se a diferença de altura entre as subárvores é maior que 1 (desbalanceado)
        if (abs(leftHeight - rightHeight) > 1) {
            isBalanced = false;  // Marca a árvore como desbalanceada
        }

        // Se já está desbalanceada, retorna -1 para propagar essa informação
        if (!isBalanced) {
            return -1;
        }

        // Retorna a altura da subárvore atual
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        dfs(root, isBalanced);  // Chama a função dfs para verificar o balanceamento
        return isBalanced;  // Retorna se a árvore está balanceada ou não
    }
};

