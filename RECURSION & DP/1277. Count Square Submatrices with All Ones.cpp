//PROBLEM :

    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


//APPROACH :
      assume ans as number of squares
      if at any index the maximum side of square is 3, incuding sq of side 1 ie itself, square of side 2, sq of side 3
        at any index i,j side of maximum possible sq is min((i-1,j-1), (i-1,j),(i,j-1)) + 1

      Hint 1
          Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
      Hint 2
          Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.

//CODE :
      class Solution {
      public:
          int countSquares(vector<vector<int>>& nums) {
              int ans = 0;
              for (int i = 0; i < nums.size(); i++) {
                  for (int j = 0; j < nums[0].size(); j++) {
                      if (i == 0 || j == 0 || nums[i][j] == 0) {
                          ans += nums[i][j];
                          continue;
                      } else {
                          nums[i][j] = min({nums[i - 1][j], nums[i][j - 1], nums[i - 1][j - 1]}) + 1;
                          ans += nums[i][j];
                      }
                  }
              }
              return ans;
          }
      };      
