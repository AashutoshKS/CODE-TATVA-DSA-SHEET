//PROBLEM :

        Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.


//CODE :
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
