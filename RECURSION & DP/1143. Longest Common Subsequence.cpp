//PROBLEM :

      Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
      
      A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order 
      of the remaining characters.
      
      For example, "ace" is a subsequence of "abcde".
      A common subsequence of two strings is a subsequence that is common to both strings.



//APPROACH :
        at index i, j if s1[i] == s2[j] increment the and, move point the pointers to i + 1, j + 1
        in case they are not equal consider 2 case
          1 -> moving pointer of s1 ie i + 1, j
          2 -> moving pointer of s2 ie i, j + 1



//CODE : RECURSION 
      class Solution {
      public:
          int solve(string text1, string text2, int idx1, int idx2) {
              if(idx1 == text1.size() || idx2 == text2.size()) return 0;
              if(text1[idx1] == text2[idx2]) return 1 + solve(text1, text2, idx1 + 1, idx2 + 1);
              return max(solve(text1, text2, idx1, idx2 + 1), solve(text1, text2, idx1 + 1, idx2));
          }
          int longestCommonSubsequence(string text1, string text2) {
              return solve(text1, text2, 0,0);
          }
      };



//CODE : DP 

      class Solution {
      public:
          int longestCommonSubsequence(string text1, string text2) {
              int m = text1.size();
              int n = text2.size();
              int arr[m + 1][n + 1];
              for (int i = 0; i <= m; i++) {
                  for (int j = 0; j <= n; j++) {
                      if (i == 0 || j == 0) 
                          arr[i][j] = 0;
                      } else {
                          if (text1[i - 1] == text2[j - 1]) {
                              arr[i][j] = arr[i - 1][j - 1] + 1;
                          } else {
                              arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                          }
                      }
                  }
              }
              return arr[m][n];
          }
      };
