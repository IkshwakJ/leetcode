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
            This is the optimized solution.
            The method works as follows:
             If a tree is completely filled or is a perfect tree, the number of nodes is 2^n - 1 
             where n is the number of levels.
             Therefore we can go to each node and check if the leftmost and the rightmost levels are
             the same if so we return the value 2^n - 1 which also accounts for itslef.
             Since the tree is complete and is filled starting from the left we can 
             state that if the tree is not a perfect one, the levels of the leftmost and the rightmost will be unequal.
             In this case we will keep going down till they match (or becomes the final node.)
        */

        if (root == nullptr)
            return 0;
        int cnt = 0; // Current node
        int lflevels = leftLevels(root);
        int rtlevels = rightLevels(root);
        if (lflevels == rtlevels)
            return (1<<lflevels) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftLevels(TreeNode* root){
        TreeNode* temp = root;
        int levels = 0;
        while(temp){
            temp = temp->left;
            levels++;
        }
        return levels;
    }
    int rightLevels(TreeNode* root){
        TreeNode* temp = root;
        int levels = 0;
        while(temp){
            temp = temp->right;
            levels++;
        }
        return levels;
    }
};