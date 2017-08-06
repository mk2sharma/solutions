/*
653. Two Sum IV - Input is a BST

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        
        vector<int> values;
        treeToVector(root, values);
        
        long target = k;
        
        for (int i = 0; i < values.size(); i++)
            if (search(values, target - values[i], i+1, values.size()-1))
                return true;
        
        return false;
    }
    
    bool search(vector<int> &values, long target, int start, int end) {
        if (start > end)
            return false;
        
        int mid = (start+end)/2;
        if (values[mid] == target)
            return true;
        
        if (values[mid] < target)
            return search(values, target, mid+1, end);
        
        return search(values, target, start, mid-1);
    }
    
    void treeToVector(TreeNode* root, vector<int> &values) {
        if (root == NULL)
            return;
        
        treeToVector(root->left, values);
        values.push_back(root->val);
        treeToVector(root->right, values);
    }
};
