/*
637. Average of Levels in Binary Tree My SubmissionsBack to Contest

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<levelInfo> info;
        averageOfLevels(root, 0, info);
        
        vector<double> result;
        for (int i = 0; i < info.size(); i++)
            result.push_back(((double)info[i].sum)/info[i].count);
        
        return result;
    }
    
    class levelInfo {
        public:
            long sum = 0;
            int count = 0;
    };

    void averageOfLevels(TreeNode* root, int level, vector<levelInfo> &info) {
        if (root == NULL)
            return;
        
        if (level >= info.size())
            info.push_back(levelInfo());
        
        info[level].sum += root->val;
        info[level].count++;
        
        averageOfLevels(root->left, level+1, info);
        averageOfLevels(root->right, level+1, info);
    }
    
    
};
