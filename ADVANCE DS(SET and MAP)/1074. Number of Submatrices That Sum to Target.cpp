//PROBLEM :

      Given a matrix and a target, return the number of non-empty submatrices that sum to target.
      
      A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
      
      Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.



//APPROACH :
      find prefix sum for each row 
      for each column use logic of leetcode 560 ie subarray sum equal k 



//COMPLEXITY :
      TIME COMPLEXITY : O(n*n*n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
              int rows = matrix.size();   
              int cols = matrix[0].size(); 
              //prefix sum of eaach rows
              for (int row = 0; row < rows; row++) {
                  for (int col = 1; col < cols; col++) {
                      matrix[row][col] += matrix[row][col - 1];
                  }
              }
      
              // Now, you need to find the "No. of subarrays with sum k" in downward
              // direction
              int result = 0;
              for (int startCol = 0; startCol < cols; startCol++) {
      
                  for (int currCol = startCol; currCol < cols; currCol++) {
                      // We need to find all sub matrices sum
                      // Now comes the concept of "No. of subarrays with sum k"
                      unordered_map<int, int> mp;
                      mp[0] = 1;
                      int sum = 0;
                      // Go downwards row wise
                      for (int row = 0; row < rows; row++) {
                          sum += matrix[row][currCol] -
                                 (startCol > 0 ? matrix[row][startCol - 1] : 0); //prefix sum from the current col 
      
                          if (mp[sum - target] > 0) {
                              result += mp[sum - target];
                          }
      
                          mp[sum]++;
                      }
                  }
              }
      
              return result;
          }
      };
