//PROBLEM :

      You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
      
      An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
      
      Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
      
      The testcases are generated so that the answer will be less than or equal to 2 * 109.



//APPROACH :
        extension of Unique path 1,
        you can reach at a point from top or left.
        but if any box contains an obstacle, total ways to reach that osition becomes 0



//CODE :
      class Solution {
      public:
          int uniquePathsWithObstacles(vector<vector<int>>& obs) {
              int n = obs[0].size();
              int m = obs.size();
              int arr[m][n];
              if (obs[m - 1][n - 1] == 1 || obs[0][0] == 1) {
                  return 0;
              }
              int k = 0;
              for(int i = 0;i< m;i++) {
                  if(k == 0 && obs[i][0] == 0) {
                      arr[i][0] = 1;
                  } else{
                      k++;
                      arr[i][0] = 0;
                  }
              }
              k = 0;
              for(int i = 0;i< n;i++) {
                  if(k == 0 && obs[0][i] == 0) {
                      arr[0][i] = 1;
                  } else{
                      k++;
                      arr[0][i] = 0;
                  }
              }
              for(int i = 1;i<m;i++) {
                  for(int j = 1;j<n;j++) {
                      if(obs[i][j] == 1) {
                          arr[i][j] = 0;
                      } else
                          arr[i][j] = arr[i-1][j] + arr[i][j-1];
                  }
              }
              return arr[m - 1][n - 1];
          }
      };        
