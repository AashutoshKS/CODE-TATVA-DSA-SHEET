//PROBLEM :
    
      Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.



//CODE :
      class Solution {
      public:
          int consecutiveNumbersSum(int n) {
              //The sum of k consecutive numbers starting from x is:
                  //Sum = x + (x + 1) + ... + (x + k - 1) = kx + (k*(k-1))/2
                  //n = kx + k*(k-1)/2  => n = kx + k*(k-1)/2 => n - k*(k-1)/2 = kx
                      // This means that:
                          // (n - k*(k-1)/2) must be divisible by k
                          // Also, n - k*(k-1)/2 >= 0 (because x must be ≥ 1)
      
              int ans = 0;
              for (int i = 1, sum = 1; sum <= n; i++, sum += i)
                  if ((n - sum) % i == 0)
                      ans++;
              return ans;
          }
      };
