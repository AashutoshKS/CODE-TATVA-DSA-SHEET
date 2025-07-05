//PROBLEM :

      The Tribonacci sequence Tn is defined as follows: 
      
      T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

      Given n, return the value of Tn.



//APPROACH :
        Same as fibbionacci series :



//CODE :

-> 1 using recursion

      class Solution {
      public:
          int tribonacci(int n) {
              if (n <= 0)
                  return 0;
              if (n == 1)
                  return 1;
              return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
          }
      };


-> 2 using DP extra space
      class Solution {
      public:
          int tribonacci(int n) {
              vector<int>ans(n+1);
              if(n==0){
                  return 0;
              }
              if(n==2 ||n==1){
                  return 1;
              }
              ans[0]=0;
              ans[1]=1;
              ans[2]=1;
              for(int i=3;i<=n;i++){
                  ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
              }
              return ans[n];
          }
      };



-> 3 using 3 variable ie O(1) space

      class Solution {
      public:
          int tribonacci(int n) {
              int fir=0;
              int sec=1;
              int thi=1;
              int ans;
              if(n==0){
                  return 0;
              }
              if(n<=2){
                  return 1;
              }
              while(n > 2){
                  ans=fir+sec+thi;
                  fir=sec;
                  sec=thi;
                  thi=ans;
                  n--;
              }
              return ans;
          }
      };
