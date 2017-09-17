/*
678. Valid Parenthesis String My SubmissionsBack to Contest

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
*/

class Solution {
public:
    bool checkValidString(string s) {
        return checkValidString(s, 0, 0);
    }
    
    bool checkValidString(string &s, int start, int count) {
        int n = s.size();
        if (start >= s.size())
            return (count == 0);
        
        for (int i = start; i < n; i++) {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')') {
                count--;
                if (count < 0)
                    return false;
            } else {
                // *
                return checkValidString(s, i+1, count+1) || checkValidString(s, i+1, count-1) || checkValidString(s, i+1, count);
            }
        }
        
        return (count == 0);
    }
    
};
