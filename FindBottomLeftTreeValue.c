/*

513. Find Bottom Left Tree Value

Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:

Input:

    2
   / \
  1   3

Output:
1

Example 2:

Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL. 
*/

unsigned int max(unsigned int first, unsigned int second) {
    return (first > second) ? first : second;
}

unsigned int getHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
        
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findLeftMostNode(struct TreeNode* root) {
    if ((root->left == NULL) && (root->right == NULL))
        return root->val;
        
    if (getHeight(root->left) >=  getHeight(root->right))
        return findLeftMostNode(root->left);
        
    return findLeftMostNode(root->right);
}
