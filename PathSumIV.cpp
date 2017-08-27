/*
666. Path Sum IV My SubmissionsBack to Contest

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.

Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
*/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<Node> nodes = convertToNode(nums);
        int result = 0;
        
        for (int i = nodes.size() - 1; i >= 0; i--) {
            for (int j = i-1; j >= 0; j--) {
                if (nodes[j].level < nodes[i].level - 1)
                    break;
                
                if (nodes[j].level == nodes[i].level)
                    continue;
                
                if (nodes[j].pos == (nodes[i].pos + 1)/2 )
                    nodes[j].children += max((int)nodes[i].children, 1);
            }
        }

        for (int i = nodes.size() - 1; i >= 0; i--) {
            // cout << i << " " << nodes[i].value << " " << nodes[i].children << endl;
            if (nodes[i].children == 0)
                result += nodes[i].value;
            else
                result += nodes[i].value * nodes[i].children;
        }
        
        return result;
    }
    
    class Node {
        public:
            unsigned int level, pos, value, children = 0;
        
            Node(unsigned int l, unsigned int p, unsigned int v):level(l), pos(p), value(v) {}
    };
    
    vector<Node> convertToNode(vector<int>& nums) {
        vector<Node> result;
        for (int n: nums) {
            result.push_back(Node(n/100, (n % 100)/10, n%10));
        }
        
        return result;
    }
};
