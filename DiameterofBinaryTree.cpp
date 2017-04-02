/*

543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        int path = 0;
        
        if (root == NULL)
            return 0;
        
        int left_height = 0, right_height = 0;
        if (root->left != NULL)
            left_height = height(root->left) + 1;
            
        if (root->right != NULL)
            right_height = height(root->right) + 1;
            
        if (left_height > right_height)
            return left_height;
            
        return right_height;
    }

    int diameterOfBinaryTree(TreeNode* root, int *max) {
        int path = 0;
        
        if (root == NULL)
            return 0;
            
        int left_height = 0, right_height = 0;
        if (root->left != NULL) {
            path = diameterOfBinaryTree(root->left, max);
            left_height = height(root->left) + 1;
        }
            
            
        if (root->right != NULL) {
            path = diameterOfBinaryTree(root->right, max);
            right_height = height(root->right) + 1;
        }
            
        if (left_height + right_height > *max)
            *max = left_height + right_height;
            
        return *max;    
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0, path;
        path = diameterOfBinaryTree(root, &max);
        return max;
    }
};
