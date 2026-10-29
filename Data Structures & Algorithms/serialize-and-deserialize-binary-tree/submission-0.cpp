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
#include <string>
#include <sstream>

class Codec {
    void serializeHelper(TreeNode* root, vector<string> &nodes) {
        if (root == NULL) {
            nodes.push_back("N");
            return;
        }

        nodes.push_back(to_string(root->val));
        serializeHelper(root->left, nodes);
        serializeHelper(root->right, nodes);
    }

    TreeNode* deserializeHelper(vector<string> &nodes, int &i){
        if(nodes[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = deserializeHelper(nodes, i);
        root->right = deserializeHelper(nodes, i);

        return root;
    }
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nodes;
        serializeHelper(root, nodes);

        string result;
        for(auto &node: nodes){
            result += node + ",";
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for(char c: data){
            if(c == ','){
                nodes.push_back(temp);
                temp.clear();
            }
            else{
                temp += c;
            }
        }

        int i = 0;
        return deserializeHelper(nodes, i);
    }
};
