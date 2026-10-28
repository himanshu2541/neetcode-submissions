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
    void kthSmallestDfs(TreeNode* root, int& k, int& ans) {
        if (root == nullptr || k == 0) return;

        kthSmallestDfs(root->left, k, ans);

        if (k == 0) return;

        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        kthSmallestDfs(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kthSmallestDfs(root, k, ans);
        return ans;
    }
};
