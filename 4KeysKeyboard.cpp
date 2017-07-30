/*
651. 4 Keys Keyboard
Imagine you have a special keyboard with the following keys:

Key 1: (A): Prints one 'A' on screen.

Key 2: (Ctrl-A): Select the whole screen.

Key 3: (Ctrl-C): Copy selection to buffer.

Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

Example 1:
Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A

Example 2:
Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Note:
1 <= N <= 50
Answers will be in the range of 32-bit signed integer.
*/

class Solution {
public:
    int maxA(int N) {
        if (N <= 3)
            return N;
        
        /*
        map<int, pair<int, int>> memo;
        memo[1] = make_pair(1, 1);
        memo[2] = make_pair(2, 1);
        memo[3] = make_pair(3, 1);
        
        return maxA(N, memo);*/
        
        map<pair<pair<int, int>, int>, int> memo;
        
        return maxA(N, 0, 1, memo);
    }
    /*
    int maxA(int N, map<int, pair<int, int>> &memo) {
        // cout << "calling maxA " << N << endl;
        map<int, pair<int, int>>::iterator it;
        it = memo.find(N);
        if (it != memo.end())
            return it->second.first;
        
        // cout << "Could not find in memo " << N << endl;
        
        int key4 = maxA(N-3, memo) * 2;
        int last = maxA(N-1, memo);
        last += memo[N-1].second;
        
        int result;
        if (key4 > last) {
            result = key4;
            memo[N] = make_pair(result, key4/2);
        } else if (key4 == last) {
            result = last;
            if (key4/2 > memo[N-1].second)
                memo[N] = make_pair(result, key4/2);
            else
                memo[N] = make_pair(result, memo[N-1].second);
        } else {
            result = last;
            memo[N] = make_pair(result, memo[N-1].second);
        }
        
        cout << N << " " << result << " " << memo[N].second << endl;
        return result;
    }*/
    
    
    
    int maxA(int remaining, int existing, int clipboard, map<pair<pair<int, int>, int>, int> &memo) {
        if (remaining == 0)
            return existing;

        if (remaining < 0)
            return 0;
        
        pair<pair<int, int>, int> p;
        p = make_pair(make_pair(existing, clipboard), remaining);
        map<pair<pair<int, int>, int>, int>::iterator it;
        it = memo.find(p);
        if (it != memo.end())
            return it->second;
        
        
        int key1 = 0, key2 = 0, key4 = 0;
        // key1 = maxA(remaining-1, existing+1, clipboard, memo);
        key2 = maxA(remaining-3, existing*2, existing, memo);
        key4 = maxA(remaining-1, existing+clipboard, clipboard, memo);
        
        int result = max(key2, key4);
        memo[p] = result;
        // cout << remaining << " " << existing << " " << clipboard << " " << result << endl;
        return result;
        
    }
};
