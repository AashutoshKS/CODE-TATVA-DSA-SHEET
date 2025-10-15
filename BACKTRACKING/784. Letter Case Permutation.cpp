//PROBLEM :

      Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
      
      Return a list of all possible strings we could create. Return the output in any order.



//APPROACH :
      Its simple backtrack
      for each charector you can either have lower case letter or upper case letter, find all such combinations



//CODE :
      class Solution {
      public:
          void solve(vector<string>&ans,int idx,string s) {
              if(idx == s.size()) {
                  ans.push_back(s);
                  return;
              }
              string s1 = s;
              if((s[idx] >= 'a' && s[idx] <= 'z')) {
                  s[idx] -= 32;
              } else if((s[idx] >= 'A' && s[idx] <= 'Z')) {
                  s[idx] += 32;
              } else {
                  solve(ans,idx + 1, s);
                  return;
              }
            // pass without changing the charector
              solve(ans,idx + 1, s1);

            //changing from upper -> lower or lower -> upper
              solve(ans,idx + 1, s);
          }
          vector<string> letterCasePermutation(string s) {
              vector<string>ans;
              solve(ans,0,s);
              return ans;
          }
      };
