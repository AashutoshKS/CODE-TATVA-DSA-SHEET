//PROBLEM :  
          Given a square matrix mat, return the sum of the matrix diagonals.
          
          Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

                    
//APPROACH :
            Simply find the diagonal sum, 
            if the size of matrix is odd then the middle diagonal will be repeated since it is common for both the diagonal 
            so in that case we have to consider that index only one time

            
//COMPLEXITY : 
            TIME COMPLEXITY : O(n)
            SPACE COMPLEXITY : O(1)

                    
//CODE
      class Solution {
      public:
          int diagonalSum(vector<vector<int>>& mat) {
              int sum=0;
              int n=mat.size();
              for(int i=0;i<n;i++){
                  sum+=mat[i][i]+mat[i][n-1-i];
              }
              if(n%2==0)
                  return sum;
              return sum-mat[n/2][n/2];
          }
      };
