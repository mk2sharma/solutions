/*
646. Maximum Length of Pair Chain My SubmissionsBack to Contest

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:
The number of given pairs will be in the range [1, 1000].
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(),
            [](vector<int> const &a, vector<int> const &b) {
                return a[0] < b[0];
            });
        
        if (pairs.size() <= 1)
            return pairs.size();
        
        vector<int> memo(pairs.size(), -1);
        return findLongestChain(pairs, -1, 0, memo);
    }
    
    bool canFit(vector<vector<int>>& pairs, int lastIndex, int curIndex) {
        if (lastIndex == -1)
            return true;
        
        return pairs[curIndex][0] > pairs[lastIndex][1];
    }

    int findLongestChain(vector<vector<int>>& pairs, int lastIndex, int curIndex, vector<int> &memo) {
        if (curIndex >= pairs.size())
            return 0;
        
        int withoutThis = findLongestChain(pairs, lastIndex, curIndex+1, memo);
        int withThis = 0;
        
        if (canFit(pairs, lastIndex, curIndex) == true)
        {
            if (memo[curIndex] == -1)
                memo[curIndex] = findLongestChain(pairs, curIndex, curIndex+1, memo);
            
            // cout << curIndex << endl;
            // cout << 5;
            withThis = 1 + memo[curIndex];
        }
        
        // cout << curIndex << " " << withoutThis << " " << withThis << endl;
        return max(withoutThis, withThis);
    }
    
};
