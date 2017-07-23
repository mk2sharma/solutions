/*
647. Palindromic Substrings My SubmissionsBack to Contest

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s.at(i-j) == s.at(i+j); j++) // odd length palindrome
                count++;

            for (int j = 1; i-j+1 >= 0 && i+j < n && s.at(i-j+1) == s.at(i+j); j++) // even length palindrome
                count++;
        }      
        
        return count;
    }
};
