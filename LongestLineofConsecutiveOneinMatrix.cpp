/*
562. Longest Line of Consecutive One in Matrix My SubmissionsBack To Contest

Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size() == 0)
            return 0;
        
        vector<vector<vector<int>>> memo(M.size());
        int i, j, k;
        for (i = 0; i < M.size(); i++) {
            vector<vector<int>> *v = new vector<vector<int>>(M[i].size());
            memo[i].insert(memo[i].end(), v->begin(), v->end());
            
            for (j = 0; j < M[i].size(); j++) {
                // memo[i].push_back(new vector<int>());
                for (k = 0; k < 8; k++)
                    memo[i][j].push_back(-1);
                // fill(memo[i][j].begin(), memo[i][j].end(), -1);
            }
        }

        int max = 0, cur;
        for (i = 0; i < M.size(); i++)
            for (j = 0; j < M[i].size(); j++) {
                cur = getCount(M, i, j, LEFT, memo);
                if (cur > max)
                    max = cur;
                
                // cout << "left " << max << endl;
                    
                cur = getCount(M, i, j, RIGHT, memo);
                if (cur > max)
                    max = cur;
                    
                // cout << "right " << max << endl;
                    
                cur = getCount(M, i, j, UP, memo);
                if (cur > max)
                    max = cur;

                // cout << "up " << max << endl;
                    
                cur = getCount(M, i, j, DOWN, memo);
                if (cur > max)
                    max = cur;

                // cout << "down " << max << endl;
                    
                    
                cur = getCount(M, i, j, DOWN_LEFT, memo);
                if (cur > max)
                    max = cur;

                // cout << "down left " << max << endl;
                    
                    
                cur = getCount(M, i, j, DOWN_RIGHT, memo);
                if (cur > max)
                    max = cur;
                    
                cur = getCount(M, i, j, UP_LEFT, memo);
                if (cur > max)
                    max = cur;
                    
                cur = getCount(M, i, j, UP_RIGHT, memo);
                if (cur > max)
                    max = cur;
                    
                // cout << "max " << max << endl;    
            }
        
        return max;
    }
    
    typedef enum {
        LEFT, RIGHT, UP, DOWN, DOWN_RIGHT, DOWN_LEFT, UP_RIGHT, UP_LEFT
    } DIR;
    
    int getCount(vector<vector<int>>& M, int i, int j, DIR d, vector<vector<vector<int>>> &memo) {
        if ((i < 0) || (i >= M.size()))
            return 0;
        
        if ((j < 0) || (j >= M[i].size()))
            return 0;
        
        if (memo[i][j][d] != -1) {
            // cout << "getCount from memo " << i << " " << j << " " << d << " " << memo[i][j][d] << endl;
            
            return memo[i][j][d];
        }

        int row, col;
        switch(d) {
            case LEFT:
                row = 0;
                col = -1;
                break;
                
            case RIGHT:
                row = 0;
                col = 1;
                break;
                
            case UP:
                row = -1;
                col = 0;
                break;
                
            case DOWN:
                row = 1;
                col = 0;
                break;
                
            case DOWN_RIGHT:
                row = 1;
                col = 1;
                break;
                
            case DOWN_LEFT:
                row = 1;
                col = -1;
                break;
                
            case UP_RIGHT:
                row = -1;
                col = 1;
                break;
                
            case UP_LEFT:
                row = -1;
                col = -1;
                break;
        }
        
        if (M[i][j] == 0)
            memo[i][j][d] = 0;
        else
            memo[i][j][d] = 1 + getCount(M, i+row, j+col, d, memo);

        // cout << "getCount " << i << " " << j << " " << d << " " << memo[i][j][d] << endl;
            
        return memo[i][j][d];   
    }
};
