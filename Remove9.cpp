/*
660. Remove 9 My SubmissionsBack to Contest
Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...

Given a positive integer n, you need to return the n-th integer after removing. Note that 1 will be the first integer.

Example 1:
Input: 9
Output: 10
Hint: n will not exceed 9 x 10^8.
*/

class Solution {
public:
    int newInteger(int n) {
        return newInteger(0, n);
    }
    
    int newInteger(int start, int n) {
        if (n < 9)
            return start+n;
        
        if (n < 81)
            return newInteger(start+10, n-9);
        
        if (n < 729)
            return newInteger(start+100, n-81);
        
        if (n < 6561)
            return newInteger(start+1000, n-729);
        if (n < 59049)
            return newInteger(start+10000, n-6561);
        if (n < 531441)
            return newInteger(start+100000, n-59049);
        if (n < 4782969)
            return newInteger(start+1000000, n-531441);
        if (n < 43046721)
            return newInteger(start+10000000, n-4782969);
        if (n < 387420489)
            return newInteger(start+100000000, n-43046721);
        
        return newInteger(start+1000000000, n-387420489);
    }
};
