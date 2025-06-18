//PROBLEM :

      Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
      
      He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in 
      $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
      
      Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

//APPROACH :
        recognize the pattern for n divisible by 7 and other


//CODE :
      class Solution {
      public:
          int totalMoney(int n) {
              int sum=0;
              if(n<=7)
                  return n*(n+1)/2;
              else if(n%7==0){
                  for(int i=0;i<n/7;i++){
                      sum=sum + 28 + 7*i; 
                  }
                  return sum;
              }
              int i;
              for(i=0;i<n/7;i++){
                  sum=sum + 28 + 7*i; 
              }
              i++;
              for(int j=0;j<n%7;j++){
                  sum+=i++;;
              }
              return sum;
          }
      };        
