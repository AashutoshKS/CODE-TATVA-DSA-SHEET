//PROBLEM :

        Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
        
        You must not use any built-in exponent function or operator.
        
        For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.



//APPROACH :
        use binary search from 1 -> maximum range
        there are 2 STL's in CPP to solve the problem both take O(logn) complexity 
                1 -> sqrt(n)
                2 -> pow(n,0.5)

//COMPLEXITY :
        TIME COMPLEXITY : O(logn)
        SPACE COMPLEXITY : O(1)

          
//CODE :
        class Solution {
        public:
            int mySqrt(int x) {
                unsigned l = 1;
                unsigned r = x + 1u;
                while (l < r) {
                    const unsigned m = (l + r) / 2;
                    if (m > x / m)
                        r = m;
                    else
                        l = m + 1;
                }
                return l - 1;
            }
        };




