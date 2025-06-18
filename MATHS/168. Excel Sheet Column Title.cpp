//PROBLEM :

      Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
      
      For example:
      
      A -> 1
      B -> 2
      C -> 3
      ...
      Z -> 26
      AA -> 27
      AB -> 28 
      ...

//APPROACH :
      while count > 0 rint the char(count/26)

        
//CODE :
      class Solution {
      public:
          string convertToTitle(int columnNumber) {
              string result = "";
              while (columnNumber > 0) {
                  columnNumber--;
                  result = char(columnNumber % 26 + 'A') + result;
                  columnNumber /= 26;
              }
              return result;
          }
      };
