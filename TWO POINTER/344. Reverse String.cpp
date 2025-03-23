//PROBLEM :
          Write a function that reverses a string. The input string is given as an array of characters s.
          You must do this by modifying the input array in-place with O(1) extra memory.

//APPROACH : 2 pointer
          using 2 pointer from start and end for swapping the charectors

//CODE :
          class Solution {
          public:
              void reverseString(vector<char>& s) {
                  int n = s.size() - 1;
                  for (int i = 0, j = n; i < j; i++, j--) {
                      char temp = s[i];
                      s[i] = s[j];
                      s[j] = temp;
                  }
              }
          };

//STL : 
          we have a CPP STL for string reversal reverse()


//CODE :
          class Solution {
          public:
              void reverseString(vector<char>& s) {
                  reverse(s.begin(),s.end());
              }
          };
