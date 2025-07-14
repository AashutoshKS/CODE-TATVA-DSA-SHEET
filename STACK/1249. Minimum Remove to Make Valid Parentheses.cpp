//PROBLEM :

        Given a string s of '(' , ')' and lowercase English characters.
        
        Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return 
          any valid string.
        
        Formally, a parentheses string is valid if and only if:
        
        It is the empty string, contains only lowercase characters, or
        It can be written as AB (A concatenated with B), where A and B are valid strings, or
        It can be written as (A), where A is a valid string.




//CODE :
      class Solution {
      public:
          string minRemoveToMakeValid(string s) {
              stack<int>check;
              for(int i=0;i<s.size();i++){
                  if(s[i]=='('){
                      check.push(i);
                  }if(s[i]==')'){
                      if(check.empty()){
                          s.erase(s.begin()+i);
                          i--;
                      }else{
                          check.pop();
                      }
                  }
              }
              while(!check.empty()){
                  int k=check.top();
                  check.pop();
                  s.erase(s.begin()+k);
              }
              return s;
          }
      };
