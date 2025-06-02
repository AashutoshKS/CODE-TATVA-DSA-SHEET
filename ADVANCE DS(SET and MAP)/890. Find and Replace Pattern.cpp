//PROBLEM :

      Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
      
      A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
      
      Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


//APPROACH :
      Check for each pair if it follows the pattern or not


//COMPLEXITY :
      TIME COMPLEXITY : O(20*n*n) = O(n*n);
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          bool check(string s, string t) {
              for(int i = 0;i < s.size(); i++) {
                  for(int j = i + 1;j < s.size(); j++) {
                      if(s[j] == s[i] && t[i] != t[j]) return false;
                      else if(s[j] != s[i] && t[i] == t[j]) return false;
                  }
              }
              return true;
          }
          vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
              vector<string>ans;
              for(int i = 0;i < words.size(); i++) {
                  if(check(pattern, words[i])) ans.push_back(words[i]);
              }
              return ans;
          }
      };
