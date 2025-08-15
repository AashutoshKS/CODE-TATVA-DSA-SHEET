//PROBLEM :

      Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.



//CODE :
      class Solution {
      public:
          int minimumDeleteSum(string s1, string s2) {
              int n = s1.size(), m = s2.size();
              vector<vector<int>>nums(s1.size() + 1, vector<int>(s2.size() + 1));
              for(int i = 0;i <= n; i++) {
                  for(int j = 0; j <= m; j++) {
                      if(i == 0 && j == 0) nums[i][j] = 0;
                      else if(j == 0) nums[i][j] = nums[i-1][j] + s1[i-1];
                      else if(i == 0) nums[i][j] = nums[i][j-1] + s2[j-1];
                      else if(s1[i-1] == s2[j-1]) nums[i][j] = nums[i-1][j-1];
                      else {
                          nums[i][j] = min(nums[i-1][j] + s1[i-1], nums[i][j-1] + s2[j-1]);
                      }
                  }
              }
              return nums[n][m];
          }
      };
