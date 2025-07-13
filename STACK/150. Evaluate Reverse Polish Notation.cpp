//PROBLEM :

      You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
      
      Evaluate the expression. Return an integer that represents the value of the expression.
      
      Note that:
      
      The valid operators are '+', '-', '*', and '/'.
      Each operand may be an integer or another expression.
      The division between two integers always truncates toward zero.
      There will not be any division by zero.
      The input represents a valid arithmetic expression in a reverse polish notation.
      The answer and all the intermediate calculations can be represented in a 32-bit integer.




//APPROACH :
      push the elemnt is the stack 
      for each operation pop the top 2 elemnts and perform the operation between them, and push to the stack


//CODE :
      class Solution {
      public:
          int evalRPN(vector<string>& tokens) {
              stack<int>ans;
              int num1,num2;
              for(int i=0;i<tokens.size();i++){
                  if(tokens[i]=="+"){
                      num1=ans.top();
                      ans.pop();
                      num2=ans.top();
                      ans.pop();
                      ans.push(num2+num1);
                  }
                  else if(tokens[i]=="*"){
                      num1=ans.top();
                      ans.pop();
                      num2=ans.top();
                      ans.pop();
                      ans.push(num2*num1);
                  }
                  else if(tokens[i]=="/"){
                      num1=ans.top();
                      ans.pop();
                      num2=ans.top();
                      ans.pop();
                      ans.push(num2/num1);
                  }
                  else if(tokens[i]=="-"){
                      num1=ans.top();
                      ans.pop();
                      num2=ans.top();
                      ans.pop();
                      ans.push(num2-num1);
                  }
                  else{
                      ans.push(stoi(tokens[i]));
                  }
              }
              return ans.top();
          }
      };
