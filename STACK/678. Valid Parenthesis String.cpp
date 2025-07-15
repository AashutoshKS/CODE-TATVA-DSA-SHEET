//PROBLEM :

      Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
      
      The following rules define a valid string:
      
      Any left parenthesis '(' must have a corresponding right parenthesis ')'.
      Any right parenthesis ')' must have a corresponding left parenthesis '('.
      Left parenthesis '(' must go before the corresponding right parenthesis ')'.
      '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".



//APPROACH :
      Check if for all closed bracket, (count of '(' + count of '*'  >= count of ')')

      after checking for all closed bracket 
      check if for all i where s[i] = '(' we have a index j where s[j] = '*' and also j > i
        



//CODE :
      class Solution {
      public:
          bool checkValidString(string s) {
              stack<int>open;
              stack<int>star;
              for(int i=0;i<s.size();i++){
                  if(s[i]=='('){
                      open.push(i);
                  }
                  if(s[i]=='*'){
                      star.push(i);
                  }
                  if(s[i]==')'){
                      if(star.empty() && open.empty()){
                          return false;
                      }
                      if(open.empty()){
                          star.pop();
                      }
                      else {
                          open.pop();
                      }
                  }
              }
              while(!open.empty()){
                  if(star.empty()){
                      return false;
                  }
                  if(open.top() < star.top()){
                      open.pop();
                      star.pop();
                  }else{
                      return false;
                  }
              }
              return true;
          }
      };
