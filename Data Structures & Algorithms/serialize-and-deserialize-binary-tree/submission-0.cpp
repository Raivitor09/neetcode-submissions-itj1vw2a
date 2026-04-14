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

class Codec {
public:
    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        if (!root) return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Helper function to tokenize the input string
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
};
