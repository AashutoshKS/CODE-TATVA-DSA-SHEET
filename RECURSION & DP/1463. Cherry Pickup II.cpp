//PROBLEM :

      You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
      
      You have two robots that can collect cherries for you:
      
      Robot #1 is located at the top-left corner (0, 0), and
      Robot #2 is located at the top-right corner (0, cols - 1).
      Return the maximum number of cherries collection using both robots by following the rules below:
      
      From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
      When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
      When both robots stay in the same cell, only one takes the cherries.
      Both robots cannot move outside of the grid at any moment.
      Both robots should reach the bottom row in grid.



//RECURSION :
      class Solution {
      public:
          int rows, cols;
      
          int solve(vector<vector<int>>& grid, int row, int col1, int col2) {
              if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
                  return 0;
              int result = 0;
              if (col1 == col2) {
                  result += grid[row][col1]; //both at same point
              } else {
                  result += grid[row][col1] + grid[row][col2]; // in case of diff points both can choose the points
              }
      
              if (row < rows - 1) {
                  int maxCherries = 0;
                  //check all possible 9 paths.......
                  for (int d1 = -1; d1 <= 1; ++d1) {
                      for (int d2 = -1; d2 <= 1; ++d2) {
                          int newCol1 = col1 + d1;
                          int newCol2 = col2 + d2;
                          maxCherries = max(maxCherries, solve(grid, row + 1, newCol1, newCol2));
                      }
                  }
                  result += maxCherries;
              }
      
              return result;
          }
      
          int cherryPickup(vector<vector<int>>& grid) {
              rows = grid.size();
              cols = grid[0].size();
              //grid, row(always same for both robots), robot1 col, robot2 col
              return solve(grid, 0, 0, cols - 1);
          }
      };




//MEMOIZATION :
      class Solution {
      public:
          int rows, cols;
          vector<vector<vector<int>>> dp;
      
          int solve(vector<vector<int>>& grid, int row, int col1, int col2) {
              if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
                  return 0;
      
              if (dp[row][col1][col2] != -1)
                  return dp[row][col1][col2];
      
              int result = 0;
              if (col1 == col2) {
                  result += grid[row][col1]; //both at same point
              } else {
                  result += grid[row][col1] + grid[row][col2]; // in case of diff points both can choose the points
              }
      
              if (row < rows - 1) {
                  int maxCherries = 0;
                  //check all possible 9 paths.......
                  for (int d1 = -1; d1 <= 1; ++d1) {
                      for (int d2 = -1; d2 <= 1; ++d2) {
                          int newCol1 = col1 + d1;
                          int newCol2 = col2 + d2;
                          maxCherries = max(maxCherries, solve(grid, row + 1, newCol1, newCol2));
                      }
                  }
                  result += maxCherries;
              }
      
              return dp[row][col1][col2] = result;
          }
      
          int cherryPickup(vector<vector<int>>& grid) {
              rows = grid.size();
              cols = grid[0].size();
              dp = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
              //grid, row(always same for both robots), robot1 col, robot2 col
              return solve(grid, 0, 0, cols - 1);
          }
      };
