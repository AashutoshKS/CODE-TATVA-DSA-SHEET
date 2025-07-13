//PROBLEM :

      Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations 
      on an initially empty stack, or false otherwise.




//APPROACH :
      Push do not have any conflict, push the element directly
      pop the element if possible, 
        check if it is a valid sequence


//CODE :
      class Solution {
      public:
          bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
              int i=0;
              stack<int> ans;
              for(int j=0;j<pushed.size();j++){
                  ans.push(pushed[j]);
                  while(!ans.empty() && ans.top()==popped[i]){
                      ans.pop();
                      i++;
                  }
              }
              return ans.empty();
          }
      };
