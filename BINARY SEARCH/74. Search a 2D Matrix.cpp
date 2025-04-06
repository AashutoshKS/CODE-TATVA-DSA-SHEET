//PROBLEM :

                You are given an m x n integer matrix matrix with the following two properties:
                
                Each row is sorted in non-decreasing order.
                The first integer of each row is greater than the last integer of the previous row.
                Given an integer target, return true if target is in matrix or false otherwise.
                
                You must write a solution in O(log(m * n)) time complexity.


//APPROACH 1 : BRUTE FORCE
                  search throught the array


//COMPLEXITY : 
                  TIME COMPLEXITY : O(n*n)
                  SPACE COMPLEXITY : O(1)



//CODE :
                  class Solution {
                  public:
                      bool searchMatrix(vector<vector<int>>& matrix, int target) {
                          int m = matrix.size();
                          int n = matrix[0].size();
                          for(int i = 0;i < m;i++) {
                              for(int j = 0;j < n;j++) {
                                  if(matrix[i][j] == target) return true;
                              }
                          }
                          return false;
                      }
                  };


//APPROACH 2 : BINARY SEARCH
                  since the list is sorted acc to both rows and cols
                  we can imagine the 2D array as a 1D array since The first integer of each row is greater than the last integer of the previous row.
                  So we can apply binary search according to this condition
                  just maintain the row, col on the basis of mid value


//COMPLEXITY : 
                  TIME COMPLEXITY : O(log(m + n))
                  SPACE COMPLEXITY : O(1)



//CODE :
                class Solution {
                public:
                    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                        int m = matrix.size();
                        int n = matrix[0].size();
                        int start = 0, end = m * n - 1, row = 0, col = 0;
                        while (start <= end && start < m * n) {
                            int mid = (start + end) / 2;
                            row = mid / n;
                            col = mid % n;
                            if (matrix[row][col] == target)
                                return true;
                            else if (matrix[row][col] < target)
                                start = mid + 1;
                            else
                                end = mid - 1;
                        }
                        return false;
                    }
                };
                
