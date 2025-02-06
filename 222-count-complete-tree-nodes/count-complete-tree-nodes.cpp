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
    int countNodes(TreeNode* root) {
        /*
            This is a brute force method and will be optimized later.
        */
        if (root == nullptr)
            return 0;
        int cnt = 1; // Current node
        if (root->right != nullptr)
            cnt += countNodes(root->right);
        if (root->left != nullptr)
            cnt += countNodes(root->left);
        return cnt; 
    }
};