//PROBLEM :

      Given a string columnTitle that represents the column title as appears in an Excel sheet, 
        return its corresponding column number.
      
      For example:
      
      A -> 1
      B -> 2
      C -> 3
      ...
      Z -> 26
      AA -> 27
      AB -> 28 
      ...


//CODE :
      class Solution {
      public:
          int titleToNumber(string s) {
              long long ans = s.back() - 'A' + 1;
              int po = 1;
              for(int i = s.size() - 2; i >= 0; i--) {
                  ans += pow(26,po)*(s[i] - 'A' + 1);
                  po++;
              }
              return ans;
          }
      };
