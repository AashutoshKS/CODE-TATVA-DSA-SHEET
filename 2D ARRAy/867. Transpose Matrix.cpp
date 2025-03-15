//PROBLEM :
    Given a 2D integer array matrix, return the transpose of matrix.
    
    The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

//APPROACH :
      since the matrix is not square we will require a extra array of size (m)(n)
      simply traverse the arr to make it transpose

//COMPLEXITY : 
          TIME COMPLEXITY : O(n*m)
          SPACE COMPLEXITY : O(n*m)
//CODE : 
      class Solution {
      public:
          vector<vector<int>> transpose(vector<vector<int>>& matrix) {
              int n = matrix.size();
              int m = matrix[0].size();
              vector<vector<int>>ans(m,vector<int>(n));
              for(int i = 0;i < m;i++) {
                  for(int j = 0; j < n;j++) {
                      ans[i][j] = matrix[j][i];
                  }
              }
              return ans;
          }
      };
