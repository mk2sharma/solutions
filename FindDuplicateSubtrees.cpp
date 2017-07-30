/*
652. Find Duplicate Subtrees
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<vector<TreeNode *>> trees;
        set<TreeNode*> dups;
        int i, j, k;
        int ignore = calcSize(root, trees, dups);
        // cout << "count " << ignore << " trees size " << trees.size() << endl;
        
        vector<TreeNode *> result;
        set<TreeNode*>::iterator it;
        for (it = dups.begin(); it != dups.end(); it++)
            result.push_back(*it);
        
        return result;
    }
    
    int calcSize(TreeNode* root, vector<vector<TreeNode *>> &trees, set<TreeNode*> &dups) {
        if (root == NULL)
            return 0;
        
        int size = calcSize(root->left, trees, dups) + calcSize(root->right, trees, dups) + 1;
        if (trees.size() <= size) 
            trees.resize(size+1);
        
        bool isDup = false;
        for (int j = 0; j < ((int)trees[size].size()); j++) {
                if (isSame(root, trees[size][j])) {
                    dups.insert(trees[size][j]);
                    isDup = true;
                }

            }
        
        if (!isDup)
            trees[size].push_back(root);
        
        return size;
    }
    
    bool isSame(TreeNode* first, TreeNode* second) {
        if ((first == NULL) && (second == NULL))
            return true;

        if ((first == NULL) || (second == NULL) || (first->val != second->val))
            return false;
        
        return isSame(first->left, second->left) && isSame(first->right, second->right);
    }
};
