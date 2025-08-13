//PROBLEM :

      Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
      
      You have the following three operations permitted on a word:
      
      Insert a character
      Delete a character
      Replace a character




//CODE :
      class Solution {
      public:
          int minDistance(string word1, string word2) {
              int m = word1.size();
              int n = word2.size();
              int arr[m+1][n+1];
              for(int i = 0; i<=m;i++) {
                  for(int j = 0;j<=n;j++) {
                      if(i == 0) arr[i][j] = j;
                      else if(j == 0) arr[i][j] = i;
                      else if(word1[i - 1] == word2[j - 1]) arr[i][j] = arr[i-1][j-1];
                      else arr[i][j] = min({arr[i-1][j],arr[i-1][j-1],arr[i][j-1]}) + 1;
                  }
              }
              return arr[m][n];
          }
      };
