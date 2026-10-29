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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(preorder, mp, preIndex, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& mp, int& preIndex, int left,
                        int right) {
        if(left > right) return NULL;

        int rootVal = preorder[preIndex++];

        TreeNode *root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        root->left = build(preorder, mp, preIndex, left, mid-1);
        root->right = build(preorder, mp, preIndex, mid+1, right);

        return root;
    }
};
