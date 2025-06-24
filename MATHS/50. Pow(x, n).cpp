//PROBLEM :

      Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
        
//NOTE
      STL IN CPP :
      pow(x,n) = x^n

//APPROACH :
        use recursion

//CODE :
      class Solution {
      public:
          double myPow(double x, long n) {
              if (n == 0)
                  return 1;
              if (n == 1)
                  return x;
              if (n < 0)
                  return 1 / myPow(x, -n);
              if (n % 2 == 1)
                  return x * myPow(x, n - 1);
              return myPow(x * x, n / 2);
          }
      };


             
