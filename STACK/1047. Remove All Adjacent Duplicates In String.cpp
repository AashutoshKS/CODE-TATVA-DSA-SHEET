//PROBLEM :

      You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
      
      We repeatedly make duplicate removals on s until we no longer can.
      
      Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



//APPROACH :
        for each iteration if prev is equal to current
        pop the prev evement


//CODE :USING STACK
      class Solution {
      public:
          string removeDuplicates(string s) {
              stack <char> v;
              for(int i=0;i<s.size();i++){
                  if(v.empty())
                  v.push(s[i]);
                  else if(s[i]==v.top())
                  v.pop();
                  else
                  v.push(s[i]);
              }
              string ans="";
              while(!v.empty()){
                  ans=v.top()+ans;
                  v.pop();
              }
              return ans;
          }
      };


//CODE : USING STRING AS STACK
      class Solution {
      public:
          string removeDuplicates(string s) {
              string ans = "";
              for(int i=0;i<s.size();i++){
                  if(ans.size() != 0 && s[i] == ans.back()) ans.pop_back();
                  else ans += s[i];
              }
              return ans;
          }
      };
