/*
658. Find K Closest Elements My SubmissionsBack to Contest

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int n = arr.size();
        int start = search(arr, x, 0, n-1);
        start = max(0, start);
        int end = min(start+k-1, n-1);
        
        if (start == 0)
            end = start+k-1;
        
        if (end == n-1)
            start = end-k+1;
        
        while ((start > 0) && (x - arr[start-1] <= arr[end] - x)) {
            start--;
            end--;
        }
        
        for (int i = start; i <= end; i++)
            result.push_back(arr[i]);
        
        return result;
    }
    
    int search(vector<int>& arr, int x, int start, int end) {
        if (start > end)
            return start;
        
        int mid = (start+end)/2;
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            return search(arr, x, mid+1, end);
        
            return search(arr, x, start, mid-1);
        
    }
};
