/*

493. Reverse Pairs

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2

Example2:

Input: [2,4,3,5,1]
Output: 3

Note:

    The length of the given array will not exceed 50,000.
    All the numbers in the input array are in the range of 32-bit integer.
*/

typedef struct _node {
    unsigned int smallCount, same;
    long val;
    struct _node *left, *right;
} node;

node * createNode(long val, unsigned int smallCount) {
    node *n = (node *) calloc (1, sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    n->smallCount = smallCount;
    n->same = 1;
    
    return n;
}

unsigned int getSmallCount(node * root, long val) {
    unsigned int smallCount = 0;
    while ((root != NULL) && (root->val != val)) {
        if (val < root->val)
            root = root->left;
        else {
            smallCount += root->same + root->smallCount;
            root = root->right;
        }
    }
    
    if (root != NULL)
        smallCount += root->smallCount;
        
    return smallCount;
}

void insert(node *root, long val) {
    node *p = root;
    
    while (root != NULL) {
        p = root;
        if (val < root->val) {
            root->smallCount++;
            // printf("Node %ld %d\n", root->val, root->smallCount);
            root = root->left;
            
        } else if (val > root->val) {
            root = root->right;
        } else {
            root->same ++;
            return;
        }
    }
    
    unsigned int smallCount = p->smallCount;
    if (val <= p->val) {
        p->left = createNode(val, 0);
    } else {
        smallCount += p->same;
        p->right = createNode(val, 0);
    }
        
}

int reversePairs(int* nums, int numsSize) {
    int count = 0, i, j;
    if ((nums == NULL) || (numsSize == 0))
        return 0;
    
    node *root = NULL;
    for (i = numsSize - 2; i >= 0 ; i--) {
        if (root == NULL)
            root = createNode((long)nums[i + 1] * 2, 0);
        else
            insert(root, (long)nums[i + 1] * 2);
        
        count += getSmallCount(root, (long)nums[i]);  
        //printf("%d %d\n", i, count);
    }
               
    return count;
}    
