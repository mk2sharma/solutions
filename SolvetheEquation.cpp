/*
640. Solve the Equation My SubmissionsBack to Contest

Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"

Example 2:
Input: "x=x"
Output: "Infinite solutions"

Example 3:
Input: "2x=x"
Output: "x=0"

Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"

Example 5:
Input: "x=x+2"
Output: "No solution"
*/

class Solution {
public:
    string solveEquation(string equation) {
        Side lhs, rhs;
        size_t eqpos = equation.find('=');
        // cout << "before converted to objects" << endl;
        lhs = convertASide(equation.substr(0, eqpos));
        // cout << "after converted lhs to objects" << endl;
        
        rhs = convertASide(equation.substr(eqpos+1));
        
        // cout << "converted to objects" << endl;
        return solve(lhs, rhs);
    }

    class Side {
        public:
            int coefficient = 0, literal = 0;
        
            Side():coefficient(0), literal(0) {
                
            }    
        
            Side operator+(Side const &s1) {
                Side s;
                s.coefficient = s1.coefficient + coefficient;
                s.literal = s1.literal + literal;

                return s;
            } 
    };
    
    
    Side convertASide(string str) {
        Side s, s1;
        string temp;
        size_t pos = str.find_first_of("+-"), cur = 0;
        while (pos != string::npos) {
            temp = str.substr(cur, pos - cur);
            // cout << "converting " << temp << endl;
            
            s1 = convertElement(temp);
            s = s + s1;
            
            cur = pos;
            pos = str.find_first_of("+-", cur + 1);
        }
        
        s1 = convertElement(str.substr(cur));
        s = s + s1;
        
        // cout << str << " coef " << s.coefficient << " lit " << s.literal << endl;
        return s;
    }
    
    string solve(Side lhs, Side rhs) {
        lhs.coefficient -= rhs.coefficient;
        rhs.literal -= lhs.literal;
        
        if ((lhs.coefficient == 0) && (rhs.literal == 0))
            return "Infinite solutions";
        
        if (lhs.coefficient == 0)
            return "No solution";
        
        string s = "x=";
        s.append(numToStr(rhs.literal/lhs.coefficient));
        return s;
    }
    
    
    Side convertElement(string s) {
        Side m;
        size_t pos = s.find('x');
        if (pos != string::npos) {
            string coef = s.substr(0, pos);
            // cout << "coef " << coef << endl;
            if (coef.empty() || (coef == "+"))
                m.coefficient = 1;
            else if (coef == "-")
                m.coefficient = -1;
            else
                m.coefficient = strToNum(coef);
        } else {
            m.literal = strToNum(s);
        }
        
        return m;
    }
    
    int strToNum(string &s) {
        int i = 0;
        
        istringstream ss(s);
        ss >> i;
        
        return i;
    }
    
    string numToStr(int num) {
        ostringstream ss;
        ss << num;
        
        return ss.str();
    }
    
    
    

};
