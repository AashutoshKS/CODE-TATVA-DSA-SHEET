//PROBLEM :
      Given an integer n, return true if it is a power of four. Otherwise, return false.
      
      An integer n is a power of four, if there exists an integer x such that n == 4x.
      
       Given an integer n, return true if it is a power of four. Otherwise, return false.
      
      An integer n is a power of four, if there exists an integer x such that n == 4x.
      


//APPROACH :
        A number is power  of four if
          -> it has only 1 set bit
          -> the set bit is at odd index ie. 0001,0100,10000.....etc


//CODE :

      class Solution {
      public:
          bool isPowerOfFour(long int n) {
              int i=0;
              if(n<=0)
                  return false;
              if(__builtin_popcount(n) != 1) return false;
              int num = 1;
              while(n > 0) {
                  int x = n&1;
                  if(x == 1) {
                      if(num%2 == 1)  return true;
                      else return false;
                  }
                  n >>= 1;
                  num++;
              }
              return 0;
          }
      };
              
