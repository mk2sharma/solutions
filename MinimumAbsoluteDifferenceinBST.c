/*

530. Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST. 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
    long last = INT_MIN, diff = INT_MAX;
    getMinDiff(root, &last, &diff);
    
    return (int)diff;
}

void getMinDiff(struct TreeNode* root, long *last, long *diff) {
    if (root == NULL)
        return;
        
    getMinDiff(root->left, last, diff);
    if (root->val - *last < *diff)
        *diff = root->val - *last;
        
    *last = root->val;
    getMinDiff(root->right, last, diff);
    return;
}
