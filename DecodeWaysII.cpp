/*
639. Decode Ways II

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:
Input: "1*"
Output: 9 + 9 = 18

Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() <= 0)
            return 0;
        
        vector<long long> memo(s.size() + 1);
        
        /*
        cout << "started actual call" << endl;
        return numDecoding(s, 0, memo); */
        
        memo.back() = 1;
        long long temp, count;
        char c, next;
        int mod = 1000000007;
        
        if (s.back() == '*')
            memo[s.size() - 1] = 9;
        else if (validPrefix(s, s.size() - 1, 1))
            memo[s.size() - 1] = 1;
        else
            memo[s.size() - 1] = 0;
        
        for (int i = s.size() - 2; i >= 0; i--) {
            count = 0;
            c = s.at(i);
            next = s.at(i+1);
            
            if (c == '*') {
                count += 9 * memo[i+1];
            } else if (validPrefix(s, i, 1))
                count += memo[i+1];

            if ((c == '*') && (next == '*')) {
                count += 15 * memo[i+2];
            } else if ((c == '1') && (next == '*')) {
                count += 9 * memo[i+2];
            } else if ((c == '2') && (next == '*')) {
                count += 6 * memo[i+2];
            } else if ((c == '*') && (next <= '6')) {
                count += 2 * memo[i+2];
            } else if ((c == '*') && (next > '6')) {
                count += memo[i+2];
            } else if (validPrefix(s, i, 2)) {
                count += memo[i+2];
            }
            
            memo[i] = count % mod;
        }
        
        return (int)memo[0];
    }
    
    int numDecoding(string &s, int start, vector<int> &memo) {
        if (start == s.size())
            return 1;
            
        if (start > s.size())
            return 0;
            
        if (memo[start] != -1)
            return memo[start];
            
        long long count = 0, temp;
        int mod = 1000000007;
        char c = s.at(start);
        
        if (c == '*') {
            temp = numDecoding(s, start + 1, memo);
            count += 9 * temp;
        } else if (validPrefix(s, start, 1))
            count += numDecoding(s, start + 1, memo);

        memo[start] = count % mod;
        if (start == s.size() - 1)
            return memo[start];
        
        char next = s.at(start + 1);
        if ((c == '*') && (next == '*')) {
            temp = numDecoding(s, start + 2, memo);
            count += 15 * temp;
        } else if ((c == '1') && (next == '*')) {
            temp = numDecoding(s, start + 2, memo);
            count += 9 * temp;
        } else if ((c == '2') && (next == '*')) {
            temp = numDecoding(s, start + 2, memo);
            count += 6 * temp;
        } else if ((c == '*') && (next <= '6')) {
            temp = numDecoding(s, start + 2, memo);
            count += 2 * temp;
        } else if ((c == '*') && (next > '6')) {
            count += numDecoding(s, start + 2, memo);
        } else if (validPrefix(s, start, 2)) {
            count += numDecoding(s, start + 2, memo);
        }
        
        memo[start] = (int)(count % mod);
        cout << "index " << start << " count " << memo[start] << endl;
        return memo[start];
    }
    
    bool validPrefix(string &s, int start, int count) {
        if (s.size() < start + count)
            return false;
            
        char min = '1', max = '9', c;
        if (count > 1)
            max = '2';
        
        for (int i = 0; i < count; i++) {
            c = s.at(start + i);
            if ((c < min) || (c > max))
                return false;
            
            min = '0';
            if (c == '2')
                max = '6';
            else
                max = '9';
        } 
        
        return true;
    }
};
