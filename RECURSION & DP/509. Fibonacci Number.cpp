//PROBLEM :

      The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
      
      F(0) = 0, F(1) = 1
      F(n) = F(n - 1) + F(n - 2), for n > 1.
      Given n, calculate F(n).

 
//APPROACH : USING RECURSION :

      class Solution {
      public:
          int fib(int n) {
              if(n<=1){
                  return n;
              }
              else{
                  return fib(n-1)+fib(n-2);
              }     
          }
      };


//APPPROACH 2 :
      using extra space (DP) to pre compute repeated subproblems

      class Solution {
      public:
          int fib(int n) {
           int arr[n + 2];
              int i;
              arr[0] = 0;
              arr[1] = 1;
              for (i = 2; i <= n; i++) {
                  arr[i] = arr[i - 1] + arr[i - 2];
              }
              return arr[n];
          }
      };


//APPROACH 3:
      most optimal using O(1) space 



      class Solution {
      public:
          int fib(int n) {
              if(n==1){
                  return 1;
              }
              int ans=0;
              int first = 0;
              int second = 1;
              n--;
              while(n > 0){
                  ans=first+second;
                  first=second;
                  second=ans;
                  n--;
              }
              return ans;
          }
      };
