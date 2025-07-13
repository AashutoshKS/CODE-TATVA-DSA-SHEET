//PROBLEM :

      Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 


SAME AS PROBLEM 316



//CODE :
      class Solution {
      public:
          string smallestSubsequence(string s) {
              vector<int> fre(26, 0);
              for (char ch : s) {
                  fre[ch - 'a']++;
              }
              vector<bool> st(26, false);
              string ans;
              for (char ch : s) {
                  fre[ch - 'a']--;
                  if (st[ch - 'a'])
                      continue;
                  while (!ans.empty() && ch < ans.back() && fre[ans.back() - 'a'] > 0) {
                      st[ans.back() - 'a'] = false;
                      ans.pop_back();
                  }
                  ans.push_back(ch);
                  st[ch - 'a'] = true;
              }
              return ans;
          }
      };
