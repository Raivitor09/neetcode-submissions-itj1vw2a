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
// PREORDER
    int maxValue = INT_MIN;
    int goodNodes(TreeNode* root) {
        return dfs(root, maxValue);
    }
    int dfs(TreeNode* root, int maxValue) {
        int res = 0;
        if(!root) return 0;

        if(root->val >= maxValue) {
            res++;
            maxValue = max(maxValue, root->val);
        }

        res += dfs(root->left, maxValue);
        res += dfs(root->right, maxValue);

        return res;
    }
};