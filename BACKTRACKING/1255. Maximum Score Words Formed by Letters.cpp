//PROBLEM :

      Given a list of words, list of  single letters (might be repeating) and score of every character.
      
      Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or 
      more times).
      
      It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 
      'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.




//CODE :
      class Solution {
      public:
          bool possible(string s, vector<int>& fre, vector<int>score, int& val) {
              for(int i = 0;i < s.size(); i++) {
                  if(fre[s[i] - 'a'] == 0) {
                      val = 0;
                      return false;
                  }
                  fre[s[i] - 'a']--;
                  val += score[s[i] - 'a'];
              }
              return true;
          }
          void solve(vector<string>& words, vector<int> fre, vector<int>score, int idx, int& ans, int curr) {
              if(idx == words.size()) {
                  ans = max(ans, curr);
                  return ;
              }
              int val = 0;
              vector<int>copy = fre;
              if(possible(words[idx], fre, score, val)) {
                  solve(words, fre, score, idx + 1, ans, curr + val);
              }
              solve(words, copy, score, idx + 1, ans, curr);
          }
          int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
              vector<int>fre(26, 0);
              for(char ch : letters) fre[ch - 'a']++;
              int ans = 0;
              solve(words, fre, score, 0, ans, 0);
              return ans;
          }
      };
