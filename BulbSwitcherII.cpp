/*
672. Bulb Switcher II

There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

Flip all the lights.
Flip lights with even numbers.
Flip lights with odd numbers.
Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

Example 1:
Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]

Example 2:
Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]

Example 3:
Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].

Note: n and m both fit in range [0, 1000].
*/

class Solution {
public:
    int flipLights(int n, int m) {
        unordered_map<string, unordered_set<string>> states;
        unordered_set<string> cur, next;
        
        if ((n <= 0) || (m < 1))
            return 1;
        
        string s;
        s.append(n, '1');
        next.insert(s);
        
        for (unsigned int i = 0; i < m; i++) {
            cur = next;
            next = unordered_set<string>();
            
            for (auto it = cur.begin(); it != cur.end(); it++) {
                if (states.find(*it) == states.end())
                    addNextStates(*it, states);
                
                next.insert(states[*it].begin(), states[*it].end());
            }
        }
        
        return next.size();
        
    }
    
    void addNextStates(const string &s, unordered_map<string, unordered_set<string>> &states) {
        char c;
        string r;
        for (char c : s) {
            r.append(1, (c == '0' ? '1' : '0'));
        }
        
        states[s].insert(r);
        // cout << "inserting " << s << " " << r << endl;
        
        r = s;
        for (unsigned int i = 1; i < s.size(); i += 2)
            r[i] = (s[i] == '0' ? '1' : '0');
        states[s].insert(r);
        // cout << "inserting " << s << " " << r << endl;
        
        r = s;
        for (unsigned int i = 0; i < s.size(); i += 2)
            r[i] = (s[i] == '0' ? '1' : '0');
        states[s].insert(r);
        // cout << "inserting " << s << " " << r << endl;
        
        r = s;
        for (unsigned int k = 0; 3*k+1 <= s.size(); k++)
            r[3*k] = (s[3*k] == '0' ? '1' : '0');
        states[s].insert(r);
        // cout << "inserting " << s << " " << r << endl;
    }
    
    
};
