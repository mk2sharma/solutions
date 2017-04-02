/*

538. Convert BST to Greater Tree

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    void GetAllKeys(TreeNode* root, vector<long> &keys) {
        if (root == NULL)
            return;
            
        GetAllKeys(root->left, keys);
        keys.push_back(root->val);
        GetAllKeys(root->right, keys);
    }

    void UpdateAllKeys(TreeNode* root, vector<long> &greater) {
        if (root == NULL)
            return;
            
        UpdateAllKeys(root->right, greater);
        root->val += greater.back();
        greater.pop_back();
        UpdateAllKeys(root->left, greater);
    }

    vector<long> GetGreaters(vector<long> &keys) {
        int i;
        vector<long> greater;
        
        if(keys.size() == 0)
            return greater;
    
        greater.push_back(0);
        long add = 0;
        for( i = keys.size() - 2; i >= 0; i-- ) {
            if (keys[i] < keys[i + 1])
                add += keys[i + 1];
                
            greater.insert(greater.begin(), add);    
        }
        
        return greater;
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<long> keys, greater;
        GetAllKeys(root, keys);
        greater = GetGreaters(keys);
        UpdateAllKeys(root, greater);
        return root;
    }
};
