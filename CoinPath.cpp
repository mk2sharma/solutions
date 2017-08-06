/*
656. Coin Path My SubmissionsBack to Contest

Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it's not possible to reach the place indexed N then you need to return an empty array.

Example 1:
Input: [1,2,4,-1,2], 2
Output: [1,3,5]

Example 2:
Input: [1,2,4,-1,2], 1
Output: []

Note:
Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
Length of A is in the range of [1, 1000].
B is in the range of [1, 100].
*/

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        map<int, pair<int, vector<int>>> memo;
        int ignore = cheapestJump(A, B, 0, memo);
        if (ignore == -1)
            return vector<int>();
        
        return memo[0].second;
    }
    
    int cheapestJump(vector<int>& A, int B, int start, map<int, pair<int, vector<int>>> &memo) {
        if ((start >= A.size()) || (A[start] == -1))
            return -1;
        
        // cout << "Calling for " << start << endl;
        
        map<int, pair<int, vector<int>>>::iterator it;
        it = memo.find(start);
        if (it != memo.end()) {
            // cout << "returning from memo " << it->second.first << endl;
            return it->second.first;
        }
        
        if (start == A.size()-1) {
            vector<int> path;
            path.push_back(start+1);
            memo[start] = make_pair(0, path);
            return 0;
        }
        
        int best = -1, cur = -1, besti;
        for (int i = 1; i <= B; i++) {
            cur = cheapestJump(A, B, start+i, memo);
            // cout << "result for " << start+i << " = " << cur << endl;
            if (cur != -1) {
                if ((best == -1) || (cur < best)) {
                    best = cur;
                    besti = start+i;
                }
            }
        }
        
        memo[start] = make_pair(best, vector<int>());
        if (best != -1) {
            memo[start].first = best + A[start];
            // cout << "Best for " << start << " = " << best + A[start] << endl;
            
            memo[start].second.push_back(start+1);
            memo[start].second.insert(memo[start].second.end(), memo[besti].second.begin(), memo[besti].second.end());
            return best + A[start];
        } else
            return best;
    }
};
