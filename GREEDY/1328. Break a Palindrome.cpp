//PROBLEM :

                Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome 
                and that it is the lexicographically smallest one possible.
                
                Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.
                
                A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding 
                character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

                  
//APPROACH :
                Change the first non 'a' character to 'a'. (not the middle one if the string is of odd lenght)
                What if the string has only 'a'?
                  Change the last character to 'b'.
                in case of len 1 return empty string


//COMPLEXITY :
              TIME COMPLEXIT : O(n)
              SPACE COMPLEXITY : O(1)



//CODE :
              class Solution {
              public:
                  string breakPalindrome(string s) {
                      if(s.size() == 1) return "";
                      int n = s.size();
                      for(int i = 0;i < s.size(); i++) {
                          if(s[i] != 'a') {
                              if(n%2 != 0 && i == n/2) continue;
                              s[i] = 'a';
                              return s;
                          }
                      }
                      s.back() = 'b';
                      return s;
                  }
              };                
