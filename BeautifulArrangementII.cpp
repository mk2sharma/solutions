/*
667. Beautiful Arrangement II My SubmissionsBack to Contest

Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
Note:
The n and k are in the range 1 <= k < n <= 104.
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<bool> chosen(n + 1, false);
        vector<int> result;
        
            result.push_back(1);
            chosen[1] = true;


        for (int i = k; i > 1; i--) {
            addMore(result, chosen, i);
        }
        
        
        for (int i = 1; i <= n; i++)
            if (!chosen[i])
                result.push_back(i);
        
        return result;
    }
    
    bool addMore(vector<int> &result, vector<bool> &chosen, int k) {
        if (k <= 1)
            return true;
        
        // cout << k << " ";
        int next = result.back() - k;
        if ((next > 1) && (next < chosen.size()) && !chosen[next]) {
            result.push_back(next);
            chosen[next] = true;
            
            return true;
        }
        
        next = result.back() + k;
        if ((next > 1) && (next < chosen.size()) && !chosen[next]) {
            result.push_back(next);
            chosen[next] = true;
            
                return true;
        }
        
        return false;
    }
};
