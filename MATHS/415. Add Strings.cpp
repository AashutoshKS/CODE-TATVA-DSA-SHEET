//PROBLEM :

      Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
      
      You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
      You must also not convert the inputs to integers directly.


//CODE :

C++ 
      class Solution {
      public:
          string addStrings(string num1, string num2) {
              reverse(num1.begin(),num1.end());
              reverse(num2.begin(),num2.end());
              string ans = "";
              int i = 0,j = 0;
              int c = 0;
              while(i < num1.size() || j < num2.size()) {
                  int num = 0;
                  if(i < num1.size()) {
                      num += num1[i] - '0';
                      i++;
                  }
                  if(j < num2.size()) {
                      num += num2[j] - '0';
                      j++;
                  }
                  num += c;
                  char ch = num%10 + '0';
                  ans.push_back(ch);
                  c = num/10;
              }
              if(c != 0) {
                  ans.push_back(char(c) +'0');
              }
              reverse(ans.begin(),ans.end());
              return ans;
          }
      };


Java Script

      /**
       * @param {string} num1
       * @param {string} num2
       * @return {string}
       */
      var addStrings = function(num3, num4) {
          let num1 = num3.split("").reverse();
          let num2 = num4.split("").reverse();
          let ans = [];
          let i = 0, j = 0, c = 0;
          while(i < num1.length || j < num2.length) {
              let num = 0;
              if(i < num1.length) {
                  num += parseInt(num1[i]);
                  i++;
              }
              if(j < num2.length) {
                  num += parseInt(num2[j]);
                  j++;
              }
              num += c;
              ans.push((num % 10).toString());
              c = Math.floor(num / 10);
          }
          if(c != 0) {
              ans.push(c.toString());
          }
          return ans.reverse().join("");
      };
