//PROBLEM :

      There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right 
        corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
      
      Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
      
      The test cases are generated so that the answer will be less than or equal to 2 * 109.


        
//CODE : RECURSION :
    If you are at position i,j  you can either move up, or left(bottom up)
    if poition is at 0,0 add 1, if position is out of bound add 0

    class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(n == 1 && m == 1) return 1;
            if(n <= 0 || m <= 0) return 0;
            return uniquePaths(m-1,n) + uniquePaths(m,n-1);
        }
    };


//CODE : DP
      make a grid of n*n
      tota count at nums[i][j] = nums[i-1][j] + nums[i][j-1]

      class Solution {
      public:
          int uniquePaths(int m, int n) {
              int arr[m][n];
              for(int i=0;i<m;i++){
                  for(int j=0;j<n;j++){
                      if(i==0 || j==0){
                          arr[i][j]=1;
                      }else{
                          arr[i][j]=arr[i-1][j]+arr[i][j-1];
                      }
                  }
              }
              return arr[m-1][n-1];
          }
      };
