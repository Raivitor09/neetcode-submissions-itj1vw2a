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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // It's a BST
            // Only compares the p e q values with the root
                // if p e q > root => means that the p e q is on the right
                // if p e q < root => means that the p e q is on the left
                // else: the LCA were found
        if (root->val < p->val && root->val < q->val) { // p and q is on the right
            return lowestCommonAncestor(root->right, p, q); 
        } else if (root->val > p->val && root->val > q->val) { // p and q is on the left
            return lowestCommonAncestor(root->left, p, q);
        } else { 
            return root; // LCA were found
        }
    }
};
