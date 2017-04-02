/*

524. Longest Word in Dictionary through Deleting

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"

Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

Note:

    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.
*/

void getMinMaxLen(vector<string>& d, int &min, int &max) {
    int len = d.size();
    min = INT_MAX;
    max = INT_MIN;
    
    for(int i = 0; i < len; i++) {
        long sz = d[i].size();
        if (d[i].size() < min)
            min = d[i].size();
            
        if (sz > max)
            max = sz;
        
    }
}

bool match(string s, string t) {
    int i = 0, j = 0;
    
    while ((i < s.size()) && (j < t.size())) {
        if (s.at(i) == t.at(j)) {
            i++;
            j++;
        } else
            i++;
    }
    
    return (j == t.size());
}


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int min, max, i, j, len = d.size();
        string result;
        
        getMinMaxLen(d, min, max);
        // cout << min << endl << max;
        for (int i = max; (i >= min); i-- ) {
            for(j = 0; j < len; j++) {
                if (d[j].size() != i)
                    continue;
                    
                // cout << "Matching " << s << " and " << d[j] << endl;
                if (match(s, d[j])) {
                    // cout << "Matched" << endl;
                    if (result.empty())
                        result = d[j];
                    else if (result.compare(d[j]) > 0)
                        result = d[j];
                }
            }
            
            if (!result.empty())
                return result;
        }
        
        return result;
    }
};
