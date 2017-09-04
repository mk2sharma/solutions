/*
670. Maximum Swap
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

Note:
The given number is in the range [0, 108]
*/

class Solution {
public:
    int maximumSwap(int num) {
        vector<unsigned int> digits, sorted_digits;
        
        if (num < 10)
            return num;
        
        unsigned int d;
        while (num > 0) {
            d = num % 10;
            digits.push_back(d);
            sorted_digits.push_back(d);
            num /= 10;
        }
        
        sort(sorted_digits.begin(), sorted_digits.end());
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            // cout << i << " " << digits[i] << " " << sorted_digits[i] << endl;
            
            if (digits[i] == sorted_digits[i])
                continue;
            
            
            for (unsigned int j = 0; j <= i; j++) {
                if (digits[j] != sorted_digits[i])
                    continue;
                
                // cout << "swap " << i << " and " << j << endl;
                d = digits[j];
                digits[j] = digits[i];
                digits[i] = d;
                break;
            }
            
            break;
        }

        int result = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            result = (result * 10) + digits[i];
        }
        
        return result;
    }
};
