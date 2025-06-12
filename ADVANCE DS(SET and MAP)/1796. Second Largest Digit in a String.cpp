//PROBLEM :

      Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
      
      An alphanumeric string is a string consisting of lowercase English letters and digits.


//APPROACH :
      count the frequency of digits
      take array of size 10 for digits 0 - 9
        return the 2nd highest digit which is present
      if not return -1




//OMPLEIXTY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(10) = O(1)


//CODE :
      class Solution {
      public:
          int secondHighest(string s) {
              vector<int>num(10);
              for(char ch : s) {
                  if(ch >= '0' && ch <= '9') {
                      num[ch - '0']++;
                  }
              }
              int k = 0;
              for(int i = 9; i >= 0; i--) {
                  if(num[i] != 0) {
                      if(k == 0) k++;
                      else return i;
                  }
              }
              return -1;
          }
      };        
