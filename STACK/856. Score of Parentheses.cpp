//PROBLEM :

      Given a balanced parentheses string s, return the score of the string.
      
      The score of a balanced parentheses string is based on the following rule:
      
      "()" has score 1.
      AB has score A + B, where A and B are balanced parentheses strings.
      (A) has score 2 * A, where A is a balanced parentheses string.




//CODE :
      class Solution {
      public:
          int scoreOfParentheses(string s) {
              stack<int>st;
              for(int i = 0;i < s.size();i++) {
                  if(s[i] == '(') {
                      st.push(-1);
                  } else {
                      int score = 0;
                      while(st.top() != -1) {
                          score += st.top();
                          st.pop();
                      }
                      st.pop();
                      st.push(max(2*score,1));
                  }
              }
              int ans = 0;
              while(!st.empty()) {
                  ans += st.top();
                  st.pop();
              }
              return ans;
          }
      };
