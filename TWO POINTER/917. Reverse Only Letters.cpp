//PROBLEM : 

              Given a string s, reverse the string according to the following rules:
              
              All the characters that are not English letters remain in the same position.
              All the English letters (lowercase or uppercase) should be reversed.
              Return s after reversing it.


//APPROACH :
                make a function check to check wether the charector at index is an alphate or not
                -> if both are alphabate swap them
                -> else the one which is not alphabate, move the pointer


//CODE :
              class Solution {
              public:
                  bool check(char ch) {
                      if(ch >= 'a' && ch <= 'z') return true;
                      if(ch >= 'A' && ch <= 'Z') return true;
                      return false;
                  }
                  string reverseOnlyLetters(string s) {
                      int i = 0,j = s.size() - 1;
                      while(i < j) {
                          if(check(s[i]) && check(s[j])) {
                              swap(s[i++],s[j--]);
                              continue;
                          }
                          if(check(s[i])) {
                              j--;
                          } else {
                              i++;
                          }
                      }
                     return s;
                  }
              };
