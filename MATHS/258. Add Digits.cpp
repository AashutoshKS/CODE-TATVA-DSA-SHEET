//PROBLEM :

      Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.



//CODE :
C++ 

      class Solution {
      public:
          int addDigits(int num) {
              int ans=0;
              if(num<10)
              return num;
              else{
                  while(num>0){
                      ans=ans+num%10;
                      num=num/10;
                  }
                  return addDigits(ans);
              }
          }
      };

-------------------------------------------------------------------------------------------
JS

      var addDigits = function(num) {
          while (num >= 10) {
              let sum = 0;
              while (num > 0) {
                  let r = num % 10;
                  num = Math.floor(num / 10);
                  sum = sum + r;
              }
              num = sum;
          }
          return num;
      };
