//PROBLEM :

      You are climbing a staircase. It takes n steps to reach the top.
      
      Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



//APPROACH :
      The pattern is the fibbonacci series use the code to return the output


//APPROACH : USING RECURSION :

      class Solution {
      public:
          int fib(int n) {
              if(n < 1){
                  return n + 1;
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
              for (i = 2; i <= n + 1; i++) {
                  arr[i] = arr[i - 1] + arr[i - 2];
              }
              return arr[n+1];
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
              while(n > 0){
                  ans=first+second;
                  first=second;
                  second=ans;
                  n--;
              }
              return ans;
          }
      };
