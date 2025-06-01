//PROBLEM :
      
      Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
      
      Integers in each row are sorted in ascending from left to right.
      Integers in each column are sorted in ascending from top to bottom.



//APPROACH :
        optimise the linear search algo using the property
        that the matrix is sorted


//CODE :
        class Solution {
        public:
            bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int m = matrix.size();
                int n = matrix[0].size();
                for(int i = 0; i < matrix.size(); i++){
                    if(target > matrix[i][n-1]) {
                        continue;
                    }
                    for(int j = 0;j<matrix[0].size();j++) {
                        if(target > matrix[m-1][j]) {
                            continue;
                        }
                        if(matrix[i][j] == target)
                            return true;
                    }
                }
                return false;
            }
        };
