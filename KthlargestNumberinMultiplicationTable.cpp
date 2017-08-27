/*
668. Kth largest Number in Multiplication Table My SubmissionsBack to Contest
Nearly every one have used the Multiplication Table. But could you find out the k-th largest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th largest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th largest number is 3 (1, 2, 2, 3, 3).

Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th largest number is 6 (1, 2, 2, 3, 4, 6).

Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (k <= 2)
            return k;
        
        return findKthNumber(m, n, k, 1, m*n);
    }
    
    int findKthNumber(int m, int n, int k, unsigned int start, unsigned int end) {
        if (start > end)
            return start;
        
        unsigned int mid = (start + end)/2;
        unsigned int smaller = getSmallerCount(m, n, mid);
        
        if (smaller == k) {
            // find smaller such mid
            while (getSmallerCount(m, n, mid-1) == k)
                mid--;
            
            return mid;
        }
        
        // cout << mid << " " << smaller << endl;
        
        if (smaller > k)
            return findKthNumber(m, n, k, start, mid-1);
        
        return findKthNumber(m, n, k, mid+1, end);
    }
    
    unsigned int getSmallerCount(const unsigned int m, const unsigned int n, const unsigned int mid) {
        unsigned int smaller = 0;
        for (int i = 1; i <= m; i++) {
            if (i * n <= mid)
                smaller += n;
            else
                smaller += mid/i;
        }
        
        return smaller;
    }
};
