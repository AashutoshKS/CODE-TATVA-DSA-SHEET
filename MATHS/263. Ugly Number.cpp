//PROBLEM :

      An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
      
      Given an integer n, return true if n is an ugly number.


//APPROACH :
      check until the number is divisible by 2, 3 and 5...
        if at any point number is not divisible by 2, 3, 5 return false

        
//CODE :

      class Solution {
      public:
          bool isUgly(int n) {
              if (n <= 0)
                  return false;
      
              while (n % 2 == 0)
                  n /= 2;
              while (n % 3 == 0)
                  n /= 3;
              while (n % 5 == 0)
                  n /= 5;
      
              if (n == 1)
                  return true;
              else
                  return false;
          }
      };
