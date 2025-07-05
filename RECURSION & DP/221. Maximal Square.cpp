//PROBLEM :
    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.



//APPROACH : 
      at any index i,j side of maximum possible sq is min((i-1,j-1), (i-1,j),(i,j-1)) + 1
      return max_side*max_side



//CODE :
      class Solution {
      public:
          int maximalSquare(vector<vector<char>>& nums) {
              int m = nums.size();
              int n = nums[0].size();
              int ans = 0;
              int arr[m][n];
              for (int i = 0; i < m; i++) {
                  for (int j = 0; j < n; j++) {
                      if (i == 0 || j == 0 || nums[i][j] == '0') {
                          if(nums[i][j] == '0') {
                              arr[i][j] = 0;
                          } else{
                              arr[i][j] = 1;
                          }
                      } else if(nums[i][j] == '1' ){
                          int mini = min(
                              {arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]});
                          arr[i][j] = mini + 1;
                      }
                      ans = max(ans, arr[i][j]);
                  }
              }
              return ans * ans;
          }
      };
