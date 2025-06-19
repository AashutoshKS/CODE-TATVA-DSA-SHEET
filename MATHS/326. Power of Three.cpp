//PROBLEM :
      Given an integer n, return true if it is a power of three. Otherwise, return false.
      
      An integer n is a power of three, if there exists an integer x such that n == 3x.



//APPROACH :
        1, 3, 9, 27, 81...
        1, 11, 1001, 11011, 1010001......
        all must be divisible by 3.....



///CODE :
      class Solution {
      public:
          bool isPowerOfThree(long int n) {
              if(n <= 0){
                  return false;
              }
              while(n != 1){
                  if(n%3 != 0){
                      return false;
                  }
                  n /= 3;
              }
              return true;
          }
      };
