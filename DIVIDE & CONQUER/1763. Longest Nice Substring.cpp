//PROBLEM :

      A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. 
      For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' 
        appears, but 'B' does not.
      
      Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of 
      the earliest occurrence. If there are none, return an empty string.



//CODE :
      Check all the strings using brte force, return the longest


//CODE :
      class Solution {
      public:
          bool valid(string s) {
              vector<int>fre(26);
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] >= 'a' && s[i] <= 'z') fre[s[i] - 'a'] = 1;
              }
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] >= 'A' && s[i] <= 'Z') {
                      if(fre[s[i] - 'A'] >= 1) fre[s[i] - 'A'] = 2;
                      else fre[s[i] - 'A'] = -1;
                  } 
              }
              for(int i = 0;i < 26;i++) {
                  if(fre[i] == 1 || fre[i] == -1) return false;
              }
              return true;
          }
          string longestNiceSubstring(string s) {
              vector<int>fre(26);
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] >= 'a' && s[i] <= 'z') fre[s[i] - 'a'] = 1;
              }
              for(int i = 0;i < s.size(); i++) {
                  if(s[i] >= 'A' && s[i] <= 'Z') {
                      if(fre[s[i] - 'A'] == 1) fre[s[i] - 'A'] = 2;
                  } 
              }
              for(int i = 0;i < 26;i++) {
                  if(fre[i] == 2) fre[i] = 1;
                  else fre[i] = 0;
              }
              string ans = "";
              for(int i = 0;i < s.size(); i++) {
                  string s1 = "";
                  for(int j = i; j < s.size(); j++) {
                      if(s[j] >= 'a' && s[j] <= 'z' && fre[s[j] - 'a'] == 0) break;
                      if(s[j] >= 'A' && s[j] <= 'Z' && fre[s[j] - 'A'] == 0) break;
                      s1 += s[j];
                      if(valid(s1) && s1.size() > ans.size()) ans = s1;
                  }
              }
              return ans;
          }
      };
