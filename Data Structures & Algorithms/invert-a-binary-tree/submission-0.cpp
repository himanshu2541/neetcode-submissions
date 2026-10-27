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
    void swap(TreeNode* node){
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        // swap
        swap(root);

        // invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
