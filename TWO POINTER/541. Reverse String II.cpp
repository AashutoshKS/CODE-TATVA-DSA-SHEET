//PROBLEM :

            Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
            
            If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
            then reverse the first k characters and leave the other as original.



//APPROACH : 
              reverse every k elements if they are in range of s
              increment the pointer 2k times since 
                -> first k must be reversed
                -> next k is ignored or left as it is


//CODE :
              class Solution {
              public:
                  string reverseStr(string s, int k) {
                      int k1 = 2*k;
                      for(int i = 0;i < s.size(); i += k1) {
                          if((i + k - 1) < s.size()) {
                              reverse(s.begin() + i,s.begin() + i + k);
                          } else {
                              reverse(s.begin() + i,s.end());
                          }
                      }
                      return s;
                  }
              };
