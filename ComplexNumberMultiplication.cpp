/*

537. Complex Number Multiplication

Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:

Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:

Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:

    The input strings will not have extra blank.
    The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/

class Solution {
public:
    class Complex {
        public:
            int real, img;
            
            Complex(int r, int i): real(r), img(i) {}
            
            Complex(string s) {
                int plus = s.find('+');
                
                istringstream r(s.substr(0, plus));
                r >> real;
                
                istringstream i(s.substr(plus + 1, s.find('i')));
                i >> img;
            }
            
            Complex mul(Complex c) {
                Complex result(real * c.real - img * c.img, real * c.img + img * c.real);
                
                return result;
            }
            
            void print() {
                cout << real << " " << img << endl;
            }
            
            string str() {
                ostringstream r;
                r << real;

                ostringstream i;
                i << img;

                string s(r.str());
                s.append(1, '+');
                s.append(i.str());
                s.append(1, 'i');
                return s;
            }
    };

    string complexNumberMultiply(string a, string b) {
        Complex c1(a), c2(b);
        
        Complex result = c1.mul(c2);
        
        return result.str();
    }
};
