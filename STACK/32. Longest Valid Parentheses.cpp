//PROBLEM :

      Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.




//APPROACH :
      initialise a stack with -1 (initial index)
      when you encounter ')', chwck if the top of stack is '('
        if yes you can form a valid parenthesis from i to top of stack



//CODE :  1
      class Solution {
      public:
          int longestValidParentheses(string s) {
              stack<int>st;
              st.push(-1);
              int ans = 0;
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] == '(') {
                      st.push(i);
                  } else {
                      st.pop();
                      if(st.empty()) st.push(i);
                      else {
                          ans = max(ans,i - st.top());
                      }
                  }
              }
              return ans;
          }
      };




//WITHOUT EXTRA SPACE  : 
      keep track of open, closed brackets


//CODEE :
      class Solution {
      public:
          int longestValidParentheses(string s) {
              int open = 0;
              int close = 0;
              int ans = 0;
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] == '(') {
                      open++;
                  } else {
                      close++;
                  }
                  if(close == open) {
                      ans = max(ans,2*open);
                  } else if(close > open){
                      open = 0;
                      close = 0;
                  }
              }
              open = 0,close = 0;
              for(int i = s.size() - 1;i >= 0; i--) {
                  if(s[i] == '(') {
                      open++;
                  } else {
                      close++;
                  }
                  if(close == open) {
                      ans = max(ans,2*open);
                  } else if(close < open){
                      open = 0;
                      close = 0;
                  }
              }
              return ans;
          }
      };
