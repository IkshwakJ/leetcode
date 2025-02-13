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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        TreeNode* node_1 = root;
        TreeNode* node_2 = root;
        while(node_1->left){
            node_1 = node_1->left;//smallest
        }
        while(node_2->right){
            node_2 = node_2->right;//largest
        }
        int sum;
        while(node_1 != node_2){
            /*
                The loop travels for the extremes to the middle.
                When the loop reach the middle, or when both nodes are at the same point, 
                we can conclude that the BST does not have the values we are searching for.
            */
            sum = node_1->val + node_2->val; 
            if(sum == k){
                return true;
            }
            if(sum<k){
                //increment the smaller number
                node_1 = inorder_next(root, node_1);
            }
            else{
                //decrement the larger number
                node_2 = inorder_prev(root, node_2);
            }
        }
        return false;
    }
private:
    TreeNode* inorder_next(TreeNode* root, TreeNode* node){
        TreeNode* next = nullptr;
        TreeNode* curr = root;
        while(curr){
            if(curr->val > node->val){
                next = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return next;
    }
    TreeNode* inorder_prev(TreeNode* root, TreeNode* node){
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while(curr){
            if(curr->val < node->val){
                prev = curr;
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return prev;
    }
};