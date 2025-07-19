//PROBLEM :

      Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
      
      An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
      
      s = s1 + s2 + ... + sn
      t = t1 + t2 + ... + tm
      |n - m| <= 1
      The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
      Note: a + b is the concatenation of strings a and b.



//APPROACH :
        we have choices if both s1[i], s2[i] != s3[i] return false;
        if one of them is equal move the pointer of (s1 or s2) and s3
        if both are equal we can make the string interleaving either by choosing s1 or s2, ie we have optionss



//CODE : RECURSION 
      class Solution {
      public:
          
          bool solve(string& s1, string &s2, string& s3, int i1, int i2, int i3) {
              if(i1 == s1.size() && i2 == s2.size() && i3 == s3.size()) return true;
              else if(i3 == s3.size()) return false;
              else if(i1 < s1.size() && s1[i1] == s3[i3] && i2 < s2.size() && s2[i2] == s3[i3]) {
                  return solve(s1, s2, s3, i1 + 1, i2, i3 +1) || solve(s1, s2, s3, i1, i2 +1, i3 +1);
              } else if(i1 < s1.size() && s1[i1] == s3[i3]) {
                  return solve(s1, s2, s3, i1 + 1, i2, i3 +1);
              } else if (i2 < s2.size() && s2[i2] == s3[i3]){
                  return solve(s1, s2, s3, i1, i2 +1, i3 +1);
              } else return false;
          }
          bool isInterleave(string s1, string s2, string s3) {
              if((s1.size()+s2.size()) != s3.size()) return false;
              return solve(s1, s2, s3, 0, 0 , 0);
          }
      };



//CODE : MEMOIZATION , 3 changing variable thus 3D DP
      class Solution {
      public:
          vector<vector<vector<int>>> dp;
          bool solve(string& s1, string& s2, string& s3, int i1, int i2, int i3) {
              if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
                  return true;
              if (i3 == s3.size())
                  return false;
              
              if (dp[i1][i2][i3] != -1)
                  return dp[i1][i2][i3];
              
              bool res = false;
      
              if (i1 < s1.size() && s1[i1] == s3[i3])
                  res |= solve(s1, s2, s3, i1 + 1, i2, i3 + 1);
      
              if (i2 < s2.size() && s2[i2] == s3[i3])
                  res |= solve(s1, s2, s3, i1, i2 + 1, i3 + 1);
      
              return dp[i1][i2][i3] = res;
          }
      
          bool isInterleave(string s1, string s2, string s3) {
              if (s1.size() + s2.size() != s3.size())
                  return false;
      
              dp = vector<vector<vector<int>>>(s1.size() + 1,vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
      
              return solve(s1, s2, s3, 0, 0, 0);
          }
      };



//CODE : DP 


      class Solution {
      public:
          bool isInterleave(string s1, string s2, string s3) {
              int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
              if(n1+n2 != n3) return 0;
              vector<bool>dp(n2 + 1);
              for(int i = 0;i <= n1; i++) {
                  for(int j = 0;j <= n2; j++) {
                      bool s1char = i > 0 && dp[j] && s1[i-1] == s3[i + j-1];
                      bool s2char = j > 0 && dp[j-1] && s2[j-1] == s3[i + j-1];
                      dp[j] = s1char || s2char || i+j == 0;
                  }
              }
              return dp.back();
          }
      };
