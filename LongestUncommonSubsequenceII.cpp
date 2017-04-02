/*
522. Longest Uncommon Subsequence II

 Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:

Input: "aba", "cdc", "eae"
Output: 3

Note:

    All the given strings' lengths will not exceed 10.
    The length of the given list will be in the range of [2, 50].
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n, max = -1;

        for (int i = 0; i < strs.size(); i ++) {
            n = GetMaxUncommonSubSeq(strs, i);
            if (n > max) {
                max = n;
                // cout << "Setting max to " << max << endl;
            }
                
        }
        
        return max;
    }

    vector<string> GetSubs(string a, int len) {
        vector<string> subs;
        if ((a.size() < len) || (len == 0))
            return subs;
            
        if (a.size() == len) {
            subs.push_back(a);
            return subs;
        }
        
        char c = a.at(0);
        subs = GetSubs(a.substr(1), len);
        vector<string> remaining = GetSubs(a.substr(1), len - 1);
        for (int i = 0; i < remaining.size(); i ++) {
            remaining[i].insert(0, 1, c);
            subs.push_back(remaining[i]);
        }
          
        return subs;  
    }
    
    // Check if a is subsequence of b
    bool IsSubSeq(string a, string b) {
        if (a.size() > b.size())
            return false;
            
        int a_index = 0;
        for (int i = 0; i < b.size(); i ++)
            if (b.at(i) == a.at(a_index)) {
                a_index ++;
                
                if (a_index >= a.size())
                    return true;
            }
            
        if (a_index >= a.size())
            return true;
            
        return false;
    }
    
    int GetMaxUncommonSubSeq(vector<string> strs, int n) {
        vector<string> subs;
        bool found;
        
        for (int i = strs[n].size(); i > 0; i --) {
            subs = GetSubs(strs[n], i);
            for (int j = 0; j < subs.size(); j++) {
                // cout << "checking " << subs[j] << endl;
                found = false;
                for (int k = 0; k < strs.size(); k ++) {
                    if (n == k)
                        continue;

                    if (IsSubSeq(subs[j], strs[k])) {
                        found = true;
                        break;
                    }
                }

                if (found == false)
                    return i;
            }
        }
        
        return -1;
    }
    
};
