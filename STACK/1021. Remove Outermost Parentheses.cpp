//PROBLEM :

        A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
        
        For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
        A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
        
        Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
        
        Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
        



//APPROACH :
        since the parethesis is valid and only consist of (, ) 
        have a variable count, which increae is s[i] == (, else decrement the count
        if s[i] is ( and count became 1, that means its the outermost starting bracket
        similarly if s[i] is ) count become 0 ,that means its the outermost closing bracket


//CODE :
      class Solution {
      public:
          string removeOuterParentheses(string s) {
              int count = 0;
              string ans="";
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] == '(') {
                      count++;
                      if(count != 1) ans += s[i];
                  } else {
                      count--;
                      if(count != 0) ans += s[i];
                  }
              }
              return ans;
          }
      };
