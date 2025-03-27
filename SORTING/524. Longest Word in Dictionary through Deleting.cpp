//PROBLEM :

              Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the
              given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. 
              If there is no possible result, return the empty string.



//APPROACH :
                -> for each string in dictionary check if the string is a substring of given string or not
                if yes return the max lenght string with least lexicographical order
                
                it is possible by 2 way
                      -> either sort the dict in order to get least lexicographical string without comparison
                      -> or do comparison each time
                
                prefer not to sort the dict in order to limit the time complexity 


//COMPLEXITY :
                TIME COMPLEXITY : O(n*n)
                SPACE COMPLEXITY : O(n)



//CODE :
              class Solution {
              public:
                  string findLongestWord(string s, vector<string>& dic) {
                      // sort(dic.begin(),dic.end());
                      string ans = "";
                      for(int i = 0;i < dic.size();i++) {
                          int n = s.size();
                          int m = dic[i].size();
                          int i1 = 0, j1= 0;
                          while(i1 < n && j1 < m) {
                              if(s[i1] == dic[i][j1]) {
                                  i1++;
                                  j1++;
                              } else {
                                  i1++;
                              }
                          }
                          if(j1 == m && j1 >= ans.size()) {
                              if(j1 == ans.size()) ans = min(ans,dic[i]);
                              else ans = dic[i];
                          } 
                      }
                      return ans;
                  }
              };
