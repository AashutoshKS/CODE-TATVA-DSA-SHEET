//PROBLEM :

      Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside 
      the signed 32-bit integer range [-231, 231 - 1], then return 0.
      
      Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



//APPROACH :
      reverse the number irrespective of their sign
      change sign after reversal
      handle the cases when th enumber is out of range of [-2^31, 2^31 - 1]


        
//COMPLEXITY :
      TIME COMPLEXITY : O(logn)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          int reverse(long int x) {
              long int y = x, r = 0;
              if (x < 0) {
                  while (-x > 0) {
                      r = r * 10 - x % 10;
                      x = x / 10;
                  }
              }
              while (x > 0) {
                  r = r * 10 + x % 10;
                  x = x / 10;
              }
              if (r > INT_MAX)
                  return 0;
              if (y > 0)
                  return r;
              return -r;
          }
      };
