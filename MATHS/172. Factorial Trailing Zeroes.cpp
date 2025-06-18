//PROBLEM :

      Given an integer n, return the number of trailing zeroes in n!.
      
      Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
      
//APPROACH :
      we can find all the factors mainly 2, 5
      return the min(count_2,count_5)
          since 5*2 = 10(trailing 0)


//APPROACH 2: Logical aptitude formula

      for any number say 125
      number of trailing 0's are
        125/5 + 125/(5*5) + 125/(5*5*5) ..... till 125/(5*5..) == 0
        25 + 5 + 1 = 31...


//CODE :
      class Solution {
      public:
          int trailingZeroes(int n) {
              int ans=0;
              for(int i=5;i<=n;i=5*i){
                  if(n/i == 0) break;
                  ans= ans+ (n/i);
              }
              return ans;
          }
      };
