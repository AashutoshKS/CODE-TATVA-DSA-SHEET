//PROBLEM : 
      Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

//APPROACH 1 : 
        traverse and count negetive number 
//COMPLEXITY : 
        TIME COMPLEXITY : O(n*n)
        SPACE COMPLEXITY : O(1)
//CODE 
      class Solution {
      public:
          int countNegatives(vector<vector<int>>& grid) {
              int count = 0;
              for(int i = 0; i <grid.size(); i++) {
                  for(int j = 0; j < grid[0].size(); j++) {
                      if(grid[i][j] < 0) count++;
                  }
              }
              return count;
          }
      };



//APPROACH 2:
          since the array is sorted if we encounter negtive number rest of the element in the row will be negetive thus we do not have to check them

//COMPLEXITY :  in worst case time is n*n but this is better approach then the 1st one
        TIME COMPLEXITY : O(n*n)
        SPACE COMPLEXITY : O(1)

//CODE
        class Solution {
        public:
            int countNegatives(vector<vector<int>>& grid) {
                int count = 0;
                for(int i = 0; i <grid.size(); i++) {
                    for(int j = 0; j < grid[0].size(); j++) {
                        if(grid[i][j] < 0) {
                            count += grid[0].size() - j;
                            break; 
                        }
                    }
                }
                return count;
            }
        };

//APPROACH 3 : 
            the same approach in 2 can be optimised 
            if we think the same way for col also...ie. if at a specific idx the value is negetive then rest element in the row and column will be negetive
            we can improve the same approach to count the negetive numbers in log (n + m) tim

//COMPLEXITY :
        TIME COMPLEXITY : O(log(n + m))
        SPACE COMPLEXITY : O(1)
              
//CODE 
        class Solution {
        public:
            int countNegatives(vector<vector<int>>& grid) {
                int m = grid.size();
                int n = grid[0].size();
                int i = m - 1, j = 0;
        
                int count = 0;
        
                while (i >= 0 && i < m && j >= 0 && j < n) {
                    if (grid[i][j] < 0) {
                        count = count + (n - j);
                        i = i - 1; 
                    } else {
                        j = j + 1;
                    }
                }
        
                return count;
            }
        };
