//PROBLEM :

      Given an integer n, return true if it is a power of two. Otherwise, return false.
      
      An integer n is a power of two, if there exists an integer x such that n == 2x.

//APPROACH :
        for a number to be power off 2 number of set bits should be 1
        num < 0 is not power of 2


//CODE 1: __builtin_popcount(n) function return the number of set bits
      class Solution {
      public:
          bool isPowerOfTwo(int n) {
              if(n < 0) return false;
              return __builtin_popcount(n) == 1;
          }
      };


//CODE 2 : Most Optimal

    //if number is power of 2 its representation would be 10000....
    //n-1 wouble be 0111111.. return n&(n-1) == 0
      class Solution {
      public:
      bool isPowerOfTwo(long int n) {
              if(n==0)
                  return false;
              return (n & (n-1))==0;
          }
      };

//CODE 3: using loop
      class Solution {
      public:
      bool isPowerOfTwo(long int n) {      
          if (n<=0)
              return false;
          unsigned int count = 0;
          while (n) {
              count += n & 1;
              n >>= 1;
          }
          
          return count==1;
          }
      };
      
      
      
      
      
