//PROBLEM :

      Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical 
      order among all possible results.



//APPROACH :
      if for using any charector,  we have multiple options check which leads to minimum string



//CODE :
      class Solution {
      public:
          string removeDuplicateLetters(string s) {
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
