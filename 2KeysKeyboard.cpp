/*
650. 2 Keys Keyboard
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
The n will be in the range [1, 1000].
*/
class Solution {
public:
    int minSteps(int n) {
        map<pair<int, int>, int> memo;
        return minSteps(n, 1, 0, 0, memo);
    }
    
    int minSteps(int n, int existing, int clipboard, int steps, map<pair<int, int>, int> &memo) {
        if (existing == n) {
            return steps;
        }
        
        if ((steps > n) || (existing > n))
            return INT_MAX;
        
        map<pair<int, int>, int>::iterator it;
        it = memo.find(make_pair(existing, clipboard));
        if (it != memo.end())
            return it->second;
        
        int copy = INT_MAX, paste = INT_MAX;
        if (existing != clipboard)
            copy = minSteps(n, existing, existing, steps + 1, memo);
        
        if (clipboard != 0)
            paste = minSteps(n, existing + clipboard, clipboard, steps + 1, memo);
        
        int result = min(copy, paste);
        memo[make_pair(existing, clipboard)] = result;
        // cout << existing << " " << clipboard << " " << steps << " " << result << endl;
        return result;
    }
};
