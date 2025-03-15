//PROBLEM :
          Given an m x n matrix, return all elements of the matrix in spiral order.
          ie. if arr = 1 2 3
                       4 5 6
                       7 8 9                 output = 1 2 3 6 9 8 7 4 5 


//APPROACH :
          take 4 pointer for left,right,top,down and play with conditions in order to solve the problem

//COMPLXITY :
          TIME COMPLEXITY : O(n*m)
          SPACE COMPLEXITY : O(m*n)


//CODE:
          class Solution {
          public:
              vector<int> spiralOrder(vector<vector<int>>& matrix) {
                  int top = 0, bottom = matrix.size() - 1;
                  int left = 0, right = matrix[0].size() - 1;
                  int n = matrix.size();
                  int m = matrix[0].size();
                  vector<int> ans;
                  while (top <= bottom && left <= right) {
                      for (int i = left; i <= right; i++) {
                          ans.push_back(matrix[top][i]);
                      }
                      top++;
                      for (int i = top; i <= bottom; i++) {
                          ans.push_back(matrix[i][right]);
                      }
                      right--;
                      if (top <= bottom) {
                          for (int i = right; i >= left; i--) {
                              ans.push_back(matrix[bottom][i]);
                          }
                          bottom--;
                      }
                      if (left <= right) {
                          for (int i = bottom; i >= top; i--) {
                              ans.push_back(matrix[i][left]);
                          }
                          left++;
                      }
                  }
                  return ans;
              }
          };
