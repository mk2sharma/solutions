/*

548. Split Array with Equal Sum

Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

    0 < i, i + 1 < j, j + 1 < k < n - 1
    Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.

where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

Example:

Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1

Note:

    1 <= n <= 2000.
    Elements in the given array will be in range [-1,000,000, 1,000,000].
*/

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
            
        map<pair<int, int>, bool> sumJconsidered;
        int i, j, k, sum, n = nums.size(), thissum;
        sum0toN(nums);
        for (int i = 1; i < n - 5; i++) {
            thissum = nums[i - 1];
            
            for (j = i + 2; j < n - 3; j++) {
                
                if (thissum != getSum(nums, i + 1, j - 1))
                    continue;
                    
                if (sumJconsidered.find(make_pair(thissum, j)) != sumJconsidered.end())
                    continue;
                    
                sumJconsidered.insert(make_pair(make_pair(thissum, j), true));
                
                for (k = j + 2; k < n - 1; k++) {
                    // cout << "i " << i << " j " << j << " k " << k << " sum " << getSum(sumTo, 0, i - 1) << endl;
                    // cout << "i " << i << " j " << j << " k " << k << " sum " << getSum(sumTo, i + 1, j - 1) << endl;
                    // cout << "i " << i << " j " << j << " k " << k << " sum " << getSum(sumTo, j + 1, k - 1) << endl;
                    // cout << "i " << i << " j " << j << " k " << k << " sum " << getSum(sumTo, k + 1, n - 1) << endl;
                    if ((thissum == getSum(nums, j + 1, k - 1)) &&
                        (thissum == getSum(nums, k + 1, n - 1)))
                            return true;
                }
            }
        }  
        
        return false;
    }
    
    void sum0toN(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i-1] + nums[i];
            // cout << " i " << i << " sum " << sum[i] << endl;
        }
    }
    
    int getSum(vector<int>& sumTo, int start, int end) {
        return sumTo[end] - sumTo[start - 1];
    }
};
