/*

514. Freedom Trail

In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
At the stage of rotating the ring to spell the key character key[i]:

    You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
    If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.

Example:

Input: ring = "godding", key = "gd"
Output: 4
Explanation:
 For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
 For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
 Also, we need 1 more step for spelling.
 So the final output is 4.

Note:

    Length of both ring and key will be in range 1 to 100.
    There are only lowercase letters in both strings and might be some duplcate characters in both strings.
    It's guaranteed that string key could always be spelled by rotating the string ring.
*/

class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
    
            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
    
    unsigned int GetClosest(string ring, char c, bool cw, int cur, int *next,
                        unordered_map<pair<int, char>, pair<int, int>, pair_hash> &charMap) {
        unsigned int steps = 0;
        int incr = 1, index = cur;

        auto res = charMap.find(make_pair(cur, c));
        if (res != charMap.end()) {
            // cout << "Found " << cur << " to " << c << endl;
            *next = (res->second).first;
            return (res->second).second;
        }

        if (cw == false)
            incr = -1;

        while(ring.at(index) != c) {
            index = index + incr;
            if (index < 0)
                index = ring.size() - 1;
            else if (index == ring.size())
                index = 0;
                
            steps ++;
        }

        charMap[make_pair(cur, c)] = make_pair(index, steps);

        // cout << "Adding from " << cur << " to " << c << " Steps: " << steps << endl;

        *next = index;
        // cout << "cur " << cur << " next " << *next << " steps " << steps << endl;
        // cout << "index " << index << " char " << c << endl;
        return steps;        
    }
    
public:
    int findRotateSteps(string ring, string key, int i, int cur, map<pair<int, int>, int> &stepsMap,
                        unordered_map<pair<int, char>, pair<int, int>, pair_hash> &charMapCW,
                        unordered_map<pair<int, char>, pair<int, int>, pair_hash> &charMapACW) {
        if (i == key.size())
            return 0;
        
        auto res = stepsMap.find(make_pair(i, cur));
        if (res != stepsMap.end()) {
            return res->second;
        }

        int cw_next, acw_next, result;
        int cw = 1 + GetClosest(ring, key[i], true, cur, &cw_next, charMapCW);
        int cw_ori = cw;
        cw += findRotateSteps(ring, key, i + 1, cw_next, stepsMap, charMapCW, charMapACW);
        
        int acw = 1 + GetClosest(ring, key[i], false, cur, &acw_next, charMapACW);
        int acw_ori = acw;
        acw += findRotateSteps(ring, key, i + 1, acw_next, stepsMap, charMapCW, charMapACW);
        
        if (cw < acw)
            result = cw;
        else
            result = acw;
        
        // cout << "cw: " << cw_ori - 1 << " acw: " << acw_ori - 1 << endl;
        // cout << "ring " << ring.at(cur) << ", cur " << cur << ", key " << key[i] << ", result " << result << endl;
        stepsMap[make_pair(i, cur)] = result;
        return result;
    }

    int findRotateSteps(string ring, string key) {
        // int acw_next;
        // return GetClosest(ring, 'r', false, 11, &acw_next);
        map<pair<int, int>, int> stepsMap;
        unordered_map<pair<int, char>, pair<int, int>, pair_hash> charMapCW, charMapACW;
        return findRotateSteps(ring, key, 0, 0, stepsMap, charMapCW, charMapACW);
    }
};
