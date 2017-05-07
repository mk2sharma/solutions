/*
573. Squirrel Simulation My SubmissionsBack To Contest
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
*/
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        memo m[nuts.size()];
        int i, maxDiff, maxNut = 0, result = 0;
        
        m[0].nut = 0;
        m[0].ds = getDistance(nuts[0], squirrel);
        m[0].dt = getDistance(nuts[0], tree);
        maxDiff = m[0].dt - m[0].ds;
        
        for (i = 1; i < nuts.size(); i++) {
            m[i].nut = i;
            m[i].ds = getDistance(nuts[i], squirrel);
            m[i].dt = getDistance(nuts[i], tree);
            
            if (m[i].dt - m[i].ds > maxDiff) {
                maxDiff = m[i].dt - m[i].ds;
                maxNut = i;
            }
        }
        
        result = m[maxNut].ds + m[maxNut].dt;
        m[maxNut].dt = 0;
        for (i = 0; i < nuts.size(); i++)
            result += m[i].dt + m[i].dt;
        
        return result;
    }
    
    class memo {
        public:
            int nut, ds, dt;
    };
    
    int getDistance(vector<int>& start, vector<int>& end) {
        int dist = start[0] - end[0];
        if (dist < 0)
            dist = 0 - dist;
            
        int other = start[1] - end[1];
        if (other < 0)
            other = 0 - other;
        
        return dist + other;
    }
    
    
};
