//PROBLEM :
                
                
                Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
                
                i - k <= r <= i + k,
                j - k <= c <= j + k, and
                (r, c) is a valid position in the matrix.


//APPROACH : 
              BRUTE FORCE use 4 loops


//COMPLEXITY :
              TIME COMPLEXITY : O(n^4)
              SPACE COMPLEXITY : O(n*n)


//CODE :
              class Solution {
              public:
                  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
                      int n = mat.size();
                      int m = mat[0].size();
                      vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
                      for (int i = 0; i < mat.size(); i++) {
                          for (int j = 0; j < mat[0].size(); j++) {
                              int sum = 0;
                              for (int i1 = 0; i1 < mat.size(); i1++) {
                                  for (int j1 = 0; j1 < mat[0].size(); j1++) {
                                      if (i1 >= max(0, i - k) && i1 <= min(n - 1, i + k) &&
                                          j1 >= max(0, j - k) && j1 <= min(m - 1, j + k)) {
                                          sum += mat[i1][j1];
                                      }
                                  }
                              }
                              ans[i][j] = sum;
                          }
                      }
                      return ans;
                  }
              };
