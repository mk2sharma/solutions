/*
681. Next Closest Time

Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

class Solution {
public:
    string nextClosestTime(string time) {
        set<unsigned int> digits = getDigits(time);
        unsigned int hour = getHour(time);
        unsigned int minute = getMinute(time);
        
        vector<unsigned int> hours = getPossibleHours(digits);
        vector<unsigned int> minutes = getPossibleMinutes(digits);
        
        unsigned int nextmin, nexthour, i;
        if (minute != minutes.back()) {
            for (i = 0; (i < minutes.size()) && (minute != minutes[i]); i++);
            
            nextmin = minutes[i+1];
            nexthour = hour;
        } else {
            nextmin = minutes[0];
            
            if (hour != hours.back()) {
                for (i = 0; (i < hours.size()) && (hour != hours[i]); i++);
                
                nexthour = hours[i+1];
            } else
                nexthour = hours[0];
        }
        
        return timeToStr(nexthour, nextmin);
    }
    
    string timeToStr(unsigned int nexthour, unsigned int nextmin) {
        ostringstream ss;
        ss << setfill('0') << setw(2) << nexthour;
        ss << ':';
        ss << setfill('0') << setw(2) << nextmin;
        
        return ss.str();
    }
    
    unsigned int strToInt(string s) {
        unsigned int i;
        istringstream ss(s);
        ss >> i;
        
        return i;
    }
    
    unsigned int getHour(string &time) {
        return strToInt(time.substr(0, 2));
    }
    
    unsigned int getMinute(string &time) {
        return strToInt(time.substr(3));
    }
    
    set<unsigned int> getDigits(string &time) {
        set<unsigned int> s;
        s.insert(time[0] - '0');
        s.insert(time[1] - '0');
        s.insert(time[3] - '0');
        s.insert(time[4] - '0');
        
        return s;
    }
    
    vector<unsigned int> getPossibleHours(set<unsigned int> &digits) {
        vector<unsigned int> result;
        unsigned int num;
        auto it1 = digits.begin();
        
        for (; it1 != digits.end(); it1++)
            for (auto it2 = digits.begin(); it2 != digits.end(); it2++) {
                num = (*it1 * 10) + *it2;
                if (num < 24) {
                    result.push_back(num);
                    // cout << "possible hour : " << num << endl;
                }
            }
        
        return result;
    }

    vector<unsigned int> getPossibleMinutes(set<unsigned int> &digits) {
        vector<unsigned int> result;
        unsigned int num;
        auto it1 = digits.begin();
        
        for (; it1 != digits.end(); it1++)
            for (auto it2 = digits.begin(); it2 != digits.end(); it2++) {
                num = (*it1 * 10) + *it2;
                // cout << num << endl;
                if (num <= 59) {
                    result.push_back(num);
                    // cout << "possible minute : " << num << endl;
                }
            }
        
        return result;
    }
};
