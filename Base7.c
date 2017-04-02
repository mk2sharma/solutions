/*

504. Base 7

Given an integer, return its base 7 string representation.

Example 1:

Input: 100
Output: "202"

Example 2:

Input: -7
Output: "-10"

Note: The input will be in range of [-1e7, 1e7]. 
*/

char* convertTo7(int num) {
    char *result = calloc(1, 20);
    bool negative = false;
    int base = 7;
    
    if (num < 0) {
        negative = true;
        num = 0 - num;
    }

    if (num == 0) {
        strcpy(result, "0");
        return result;
    }
    
    char *buffer = calloc(1, 20);
    while (num != 0) {
        int digit = num % base;
        
        switch (digit) {
            case 0: 
                *buffer = '0';
                break;
                
            case 1: 
                *buffer = '1';
                break;
 
             case 2: 
                *buffer = '2';
                break;
 
             case 3: 
                *buffer = '3';
                break;
 
             case 4: 
                *buffer = '4';
                break;
 
             case 5: 
                *buffer = '5';
                break;
 
             case 6: 
                *buffer = '6';
                break;
        }
    
        *(buffer + 1) = '\0';

        strcat(buffer, result);
        strcpy(result, buffer);
        num = num / 7;
    }
    
    if (negative) {
        strcpy(buffer, "-");
        strcat(buffer, result);
        strcpy(result, buffer);
    }
    
    free(buffer);
    return result;
}

