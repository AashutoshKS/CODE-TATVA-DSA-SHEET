//PROBLEM : 

      You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.
      
      Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n 
        has less than k factors.


//APPROACH :
      find all factor using loop from 1-n
        return the kth factor


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          int kthFactor(int n, int k) {
              int k1 = 0;
              for (int i = 1; i <= n; i++) {
                  if (n % i == 0)
                      k1++;
                  if (k1 == k)
                      return i;
              }
              return -1;
          }
      };
