//PROBLEM :

      Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
      
      An input string is valid if:
      
      Open brackets must be closed by the same type of brackets.
      Open brackets must be closed in the correct order.
      Every close bracket has a corresponding open bracket of the same type.



//APPROACH : 
      use stack of char to keep record of the previous opening bracket 
      if at the end st is empty return true



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          bool isValid(string s) {
              stack<char> st;
              for(int i=0;i<s.length();i++)
              {
                  if(s[i]=='(')
                      st.push(')');
                  else if(s[i]=='[')
                      st.push(']');
                  else if(s[i]=='{')
                      st.push('}');
                  else
                  {
                      if(st.empty() || st.top()!=s[i])
                          return false;
                      st.pop();
                  }
              }
              return st.empty();
          }
      };
