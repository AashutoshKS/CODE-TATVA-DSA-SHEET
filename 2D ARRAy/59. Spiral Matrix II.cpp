//PROBLEM :
        Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

          ex if n == 3 
          elements in array = 1 2 3 4 5 6 7 8 9
          matrix in spiral order : 
          1 2 3
          8 9 4
          7 6 5



//APPROACH :
          since row and col are equal we do not need a extra condition simply solve same as SPIRAL MATRIX I 

//COMPLEXITY :
          TIME COMPLEXITY O (n*n);
          SPACE COMPLEXITY : O(n*n);

//CODE : 
          class Solution {
          public:
              vector<vector<int>> generateMatrix(int n) {
                  int num = 1;
                  int top = 0, bottom = n - 1;
                  int left = 0, right = n - 1;
                  vector<vector<int>>arr(n,vector<int>(n));
                  while (top <= bottom && left <= right) {
                      for (int i = left; i <= right; i++) {
                          arr[top][i] = num++;
                      }
                      top++;
                      for (int i = top; i <= bottom; i++) {
                          arr[i][right] = num++;
                      }
                      right--;
                      for (int i = right; i >= left; i--) {
                          arr[bottom][i] = num++;
                      }
                      bottom--;
                      for (int i = bottom; i >= top; i--) {
                          arr[i][left] = num++;
                      }
                      left++;
                  }
                  return arr;
              }
          };
