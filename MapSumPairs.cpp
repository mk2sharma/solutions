/*
677. Map Sum Pairs My SubmissionsBack to Contest

Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/

class Trie {
public:
    Trie *child[128] = { NULL };
    int sum = 0;
    
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int sum) {
        Trie *parent = this;
        
        for (int i = 0; i < word.size(); i++) {
            if (parent->child[word.at(i)] == NULL)
                parent->child[word.at(i)] = new Trie();
            
            parent = parent->child[word.at(i)];
        }
        
        parent->sum = sum;
    }
    
    int getSum(string word) {
        Trie *parent = this;
        
        for (int i = 0; i < word.size(); i++) {
            if (parent->child[word.at(i)] == NULL)
                return false;
            
            parent = parent->child[word.at(i)];
        }
        
        return getSum(parent);
        
    }
    
    int getSum(Trie *n) {
        if (n == NULL)
            return 0;
        
        int s = n->sum;
        for (int i = 0; i < 128; i++)
            s += getSum(n->child[i]);
        
        return s;
    }
    
};


class MapSum {
public:
    Trie t;
    
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        t.insert(key, val);
    }
    
    int sum(string prefix) {
        return t.getSum(prefix);
    }
};



/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
