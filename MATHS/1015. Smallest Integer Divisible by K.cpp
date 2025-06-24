//PROBLEM :

      Given a positive integer k, you need to find the length of the smallest +ve integer n such that n is divisible by k, 
      and n only contains the digit 1.
      
      Return the length of n. If there is no such n, return -1.
      
      Note: n may not fit in a 64-bit signed integer.


//APPROACH :
      Check all the possible numbers which has only 1 by adding n * 10 + 1
      if at any time we have former the number previously return -1 ie it is not possible 

      Hint 1
          11111 = 1111 * 10 + 1 We only need to store remainders modulo K.
      Hint 2
          If we never get a remainder of 0, why would that happen, and how would we know that?



///COMPLEXITY :
      TIME COMPLEXITY : O(k)
      SPACE COMPLEITY : O(n)



//CODE :
      class Solution {
      public:
          int smallestRepunitDivByK(int k) {
              if (k % 2 == 0)
                  return -1;
              unordered_set<int> seen;
              int n = 0;
              for (int i = 1; i <= k; i++) {
                  n = (n * 10 + 1) % k;
                  if (n == 0)
                      return i;
                  if (seen.contains(n))
                      return -1;
                  seen.insert(n);
              }
              return -1;
          }
      };
