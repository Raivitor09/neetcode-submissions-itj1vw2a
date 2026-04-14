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
public:
    void inOrder(TreeNode* node, vector<int>& elements) {
        if (!node) return;

        inOrder(node->left, elements);
        elements.push_back(node->val); // 1 2 3 4(already sorted)
        inOrder(node->right, elements);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> elements;
        inOrder(root, elements); 
        // dont need to sort, because the inOrder traversal already came with an ascending order

        return elements[k-1];
    }
}; 
// Time: O(n)
// Space: O(n)
