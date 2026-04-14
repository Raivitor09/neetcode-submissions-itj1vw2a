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
    bool isBST(TreeNode* root, long lower, long upper) {
        if (!root) return true;

        if (root->val <= lower || root->val >= upper) return false;

        return isBST(root->left, lower, root->val) && isBST (root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        long num_min = LONG_MIN;
        long num_max = LONG_MAX;
        return isBST(root, num_min, num_max);
    }
};
