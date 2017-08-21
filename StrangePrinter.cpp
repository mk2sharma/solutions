/*
664. Strange Printer

There is a strange printer with the following two special requirements:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

Hint: Length of the given string will not exceed 100.
*/

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
        
        for (int i = 1; i < s.size(); i++)
            for (int j = 0; j < n-i; j++) {
                dp[j][j+i] = dp[j][j+i-1] + 1;
                for (int k = j; k < j+i; k++)
                    if (s[k] == s[j+i])
                        dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] - 1);
            }
                
        return dp[0][n-1];
    }
};
