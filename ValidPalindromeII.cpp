/*
680. Valid Palindrome II My SubmissionsBack to Contest
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size()-1, false);
    }

    bool validPalindrome(string &s, int l, int r, bool mismatch) {
        while (l < r) {
            if (s[l] != s[r]) {
                if (mismatch)
                    return false;
                
                return validPalindrome(s, l+1, r, true) || validPalindrome(s, l, r-1, true);
            }
            
            l++;
            r--;
        }
        
        return true;
    }
};
