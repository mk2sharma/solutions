/*
515. Find Largest Value in Each Tree Row

You need to find the largest value in each row of a binary tree.

Example:

Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

unsigned int max(unsigned int first, unsigned int second) {
    return (first > second) ? first : second;
}

unsigned int getHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
        
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void updateMax(struct TreeNode* root, unsigned int level, int *result) {
    if (root == NULL)
        return;

    if (root->val > result[level])
        result[level] = root->val;
        
    updateMax(root->left, level + 1, result);
    updateMax(root->right, level + 1, result);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findValueMostElement(struct TreeNode* root, int* returnSize) {
    if (returnSize == NULL)
        return NULL;
        
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
        
    *returnSize = getHeight(root);
    int *result = (int *) calloc(*returnSize, sizeof(int));
    
    for (unsigned int i = 0; i < *returnSize; i++)
        result[i] = INT32_MIN;
    
    updateMax(root, 0, result);
    return result;
}
