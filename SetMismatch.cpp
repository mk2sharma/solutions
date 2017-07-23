/*
645. Set Mismatch My SubmissionsBack to Contest

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> exist(nums.size()+1, false);
        long sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            exist[nums[i]] = true;
            sum += nums[i];
        }
        
        int n = nums.size();
        long expected_sum = (((long)n) * (n+1))/2;
        long diff = expected_sum - sum;
        vector<int> result(2);
        for (int i = 1; i < exist.size(); i++) {
            if (exist[i] == false) {
                result[1] = i;
                break;
            }
        }

        result[0] = result[1] - diff;
        return result;
        
    }
};
