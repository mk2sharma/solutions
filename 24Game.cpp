/*
679. 24 Game My SubmissionsBack to Contest

You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24

Example 2:
Input: [1, 2, 1, 2]
Output: False

Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

class Solution {
public:
    bool judgePoint24(vector<int>& b) {
        vector<float> cur, t = getAllResults(b[0], b[1], b[2]);
        for (float a : t) {
            cur = getAllResults(b[3], a);
            if (find(cur.begin(), cur.end(), 24) != cur.end())
                return true;
        }
        
        t = getAllResults(b[3], b[1], b[2]);
        for (float a : t) {
            cur = getAllResults(b[0], a);
            if (find(cur.begin(), cur.end(), 24) != cur.end())
                return true;
        }
        
        t = getAllResults(b[0], b[1], b[3]);
        for (float a : t) {
            cur = getAllResults(b[2], a);
            if (find(cur.begin(), cur.end(), 24) != cur.end())
                return true;
        }
        
        t = getAllResults(b[0], b[3], b[2]);
        for (float a : t) {
            cur = getAllResults(b[1], a);
            if (find(cur.begin(), cur.end(), 24) != cur.end())
                return true;
        }
        
        vector<float> t1, t2;
        t1 = getAllResults(b[0], b[1]);
        t2 = getAllResults(b[2], b[3]);
        
        for (float t1c : t1)
            for (float t2c : t2) {
                cur = getAllResults(t1c, t2c);
                if (find(cur.begin(), cur.end(), 24) != cur.end())
                    return true;
            }
        
        t1 = getAllResults(b[0], b[2]);
        t2 = getAllResults(b[1], b[3]);
        
        for (float t1c : t1)
            for (float t2c : t2) {
                cur = getAllResults(t1c, t2c);
                if (find(cur.begin(), cur.end(), 24) != cur.end())
                    return true;
            }
        
        t1 = getAllResults(b[0], b[3]);
        t2 = getAllResults(b[1], b[2]);
        
        for (float t1c : t1)
            for (float t2c : t2) {
                cur = getAllResults(t1c, t2c);
                if (find(cur.begin(), cur.end(), 24) != cur.end())
                    return true;
            }
        
        return false;
    }

    vector<float> getAllResults(float n1, float n2, float n3) {
        vector<float> r, cur;
        
        vector<float> t = getAllResults(n1, n2);
        for (float a : t) {
            cur = getAllResults(n3, a);
            r.insert(r.end(), cur.begin(), cur.end());
        }
        
        t = getAllResults(n1, n3);
        for (float a : t) {
            cur = getAllResults(n2, a);
            r.insert(r.end(), cur.begin(), cur.end());
        }
        
        t = getAllResults(n3, n2);
        for (float a : t) {
            cur = getAllResults(n1, a);
            r.insert(r.end(), cur.begin(), cur.end());
        }
        
        return r;
    }
    
    vector<float> getAllResults(float n1, float n2) {
        vector<float> r;
        r.push_back(n1 + n2);
        r.push_back(n1 - n2);
        r.push_back(n2 - n1);
        r.push_back(n1 * n2);
        
        if (n2 != 0)
            r.push_back(n1/n2);
        
        if (n1 != 0)
            r.push_back(n2/n1);
        
        return r;
    }
};
