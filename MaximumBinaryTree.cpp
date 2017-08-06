/*
654. Maximum Binary Tree My SubmissionsBack to Contest

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;
        
        int rootIndex = getMax(nums, start, end);
        TreeNode *n = new TreeNode(nums[rootIndex]);
        n->left = constructMaximumBinaryTree(nums, start, rootIndex-1);
        n->right = constructMaximumBinaryTree(nums, rootIndex+1, end);
        return n;
    }
    
    int getMax(vector<int>& nums, int start, int end) {
        int result = start;
        for (int i = start+1; i <= end; i++)
            if (nums[i] > nums[result])
                result = i;
        
        return result;
    }
};
