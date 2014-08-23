/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        //leaf node
        if(root->left == nullptr && root->right == nullptr) return 1;
        if(root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
        if(root->left) return 1 + minDepth(root->left);
        else return 1 + minDepth(root->right);
    }
};
