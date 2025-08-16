//PROBLEM :

      Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
      
      Note that the same word in the dictionary may be reused multiple times in the segmentation.



//CODE : BRUTE : (Java)
      class Solution {
          private boolean solve(String s,Set<String> set,int start){
              if(start==s.length()){
                  return true;
              }
              for(int end = start+1;end<=s.length();end++){
                  if(set.contains(s.substring(start,end)) && solve(s,set,end)){
                      return true;
                  }
              }
              return false;
          }
          public boolean wordBreak(String s, List<String> wordDict) {
              Set<String> set = new HashSet<>(wordDict);
              return solve(s,set,0);
          }
      }




//CODE : DP : C++
      class Solution {
      public:
          bool wordBreak(string s, vector<string>& wordDict) {
              int n = s.length();
              unordered_set<string> st(wordDict.begin(), wordDict.end());
              vector<bool> dp(n + 1);
              dp[0] = true;
      
              for (int i = 1; i <= n; ++i) {
                  for (int j = 0; j < i; ++j) {
                      if (dp[j] && st.contains(s.substr(j, i - j))) {
                          dp[i] = true;
                          break;
                      }
                  }
              }
              return dp[n];
          }
      };
