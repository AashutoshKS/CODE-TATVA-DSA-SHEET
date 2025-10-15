//PROBLEM : 

        Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


//APPROACH :
          just keep a track that how many '(' open brackets you have used.....use '(' k times only
          check all possibility 
            like for each index you can either use
              i) ')' if number of '(' are < ')'
              ii) '(' until its count is k
          check all combinations and return them


//CODE :

      class Solution {
          void parentheses(int open, int close,int n,string s, vector<string>& v){
              if(s.size() == (2*n)){
                  v.push_back(s);
                  return;
              }
              if(open < n){
                  parentheses(open + 1, close,n, s + '(', v);
              }
              if(close < open){
                  parentheses(open , close + 1,n, s + ')', v);
              }
          }
      public:
      
          vector<string> generateParenthesis(int n) {
              vector<string>v;
              parentheses(0,0,n,"", v);
              return v;
          }
      };
