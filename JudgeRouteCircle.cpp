/*
657. Judge Route Circle My SubmissionsBack to Contest

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        char c;
        for (int x = 0; x < moves.size(); x++) {
            c = moves.at(x);
            if (c == 'L')
                i--;
            
            if (c == 'R')
                i++;
            
            if (c == 'U')
                j--;
            
            if (c == 'D')
                j++;
            
        }
        
        return (i == 0) && (j == 0);
    }
};
