/*

542. 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:

0 0 0
0 1 0
0 0 0

Output:

0 0 0
0 1 0
0 0 0

Example 2:
Input:

0 0 0
0 1 0
1 1 1

Output:

0 0 0
0 1 0
1 2 1

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    int getValue(vector<vector<int>>& matrix, vector<vector<int>>& result, int i, int j, int depth) {
        if ((i < 0) || (i >= result.size()) || (j < 0) || (j >= result[i].size()))
            return INT32_MAX - 1;
            
        updateResult(matrix, result, i, j, depth + 1);
        return result[i][j];
    }

    void updateResult(vector<vector<int>>& matrix, vector<vector<int>>& result, int i, int j, int depth) {
        if ((i < 0) || (i >= matrix.size()) || (j < 0) || (j >= matrix[i].size()))
            return;
        
        if (depth >= (matrix.size() + matrix[0].size()))
            result[i][j] = matrix.size() + matrix[0].size();
        
        if (result[i][j] == 0)
            return;
            
        if (result[i][j] == -1) {
            int min = getValue(matrix, result, i + 1, j, depth), value;
            if (min != 0) {
                value = getValue(matrix, result, i - 1, j, depth);
                if (value < min)
                    min = value;

                if (min != 0) {
                    value = getValue(matrix, result, i, j + 1, depth);
                    if (value < min)
                        min = value;
                     
                    if (min != 0) { 
                        value = getValue(matrix, result, i, j - 1, depth);
                        if (value < min)
                            min = value;
                    
                    }
                    
                }                    
                
            }
                
            result[i][j] = min + 1;
            cout << "Setting " << i << " " << j << " " << " to " << min << endl;
        }
    }

    bool valid(vector<vector<int>>& result, int i, int j) {
        if ((i < 0) || (i >= result.size()) || (j < 0) || (j >= result[i].size()))
            return false;
        
        return true;
    }

    void update(vector<vector<int>>& result, int i, int j, int next, int &count) {
        if (valid(result, i, j) && (result[i][j] == -1)) {
            result[i][j] = next;
            count ++;            
        }
    }    

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int i, j, count = 0, total = matrix.size() * matrix[0].size();
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
        int next = 0;
        
        for (i = 0; i < matrix.size(); i++)
            for (j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                    count ++;
                }
                else
                    result[i][j] = -1;
            }
        
        while (count < total) {
            for (i = 0; i < matrix.size(); i++)
                for (j = 0; j < matrix[i].size(); j++) {
                    if (result[i][j] == next) {
                        update(result, i + 1, j, next + 1, count);
                        update(result, i - 1, j, next + 1, count);
                        update(result, i, j + 1, next + 1, count);
                        update(result, i, j - 1, next + 1, count);
                    }
                        
                }
            
            next++;
        }    
            
        return result;
    }
};
