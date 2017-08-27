/*
665. Non-decreasing Array My SubmissionsBack to Contest

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000].
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2)
            return true;
        
        set<unsigned int> candidates;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i+1]) {
                candidates.insert(i);
                candidates.insert(i+1);
                
            }
        
        if (candidates.size() >= 3)
            return false;
        
        if (candidates.size() == 0)
            return true;
        
        bool mismatch;
        int j;
        for (int i : candidates) {
            mismatch = true;
            for (j = 1; j < nums.size() - 1; j++) {
                if (j == i+1)
                    continue;
                
                if (j == i) {
                    if (nums[j+1] < nums[j-1])
                        break;
                } else if (nums[j] < nums[j-1])
                    break;
            }
            
            if (j == nums.size() - 1) {
                if ((i == j) || (nums[j] >= nums[j-1]))
                    return true;
            }
            
            
        }
        
        return false;
    }
};
