/*
683. K Empty Slots

There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.

Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1

Note:
The given array will be in the range [1, 20000].
*/

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size(), result = -1, cur, dqfront;
        int i;
        
        if (k > n-2)
            return -1;
        
        vector<int> pots(n);
        for (i = 0; i < flowers.size(); i++)
            pots[flowers[i]-1] = i+1;

        // for (i = 0; i < flowers.size(); i++)
        //    cout << pots[i] << " ";
        
        deque<int> dq;
        for (i = 0; i < (n-1); i++) {
            // cout << i << " " << pots[i] << " ";
            while ((!dq.empty()) && (pots[dq.back()] > pots[i])) {
                // cout << "removed " << pots[dq.back()] << " ";
                dq.pop_back();
            }
            
            dq.push_back(i);
            while ((!dq.empty()) && (dq.front() <= i-k)) {
                // cout << "removed front " << pots[dq.front()] << " ";
                dq.pop_front();
            }
            
            dqfront = dq.empty() ? 0 : dq.front();
            
            // cout << pots[dq.front()] << endl;
            
            if ((i >= k) && (pots[i-k] < pots[dqfront]) && (pots[i+1] < pots[dqfront])) {
                cur = max(pots[i-k], pots[i+1]);
                // cout << "Found " << cur << endl;
                if ((result == -1) || (result > cur))
                    result = cur;
            }
        }
            
        return result;
    }
};
