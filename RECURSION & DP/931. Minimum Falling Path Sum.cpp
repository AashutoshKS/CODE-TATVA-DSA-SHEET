//PROBLEM :

      Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
      
      A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
        Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


//APPROACH :
      you can move to 3 positions start from top row till bottom orw
      selecting the most optimal direction


//CODE :
        class Solution {
        public:
            int minFallingPathSum(vector<vector<int>>& matrix) {
                int m = matrix[0].size();
                int n = matrix.size();
                int arr[m][n];
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == 0) {
                            arr[i][j] = matrix[i][j];
                        } else if (j == 0) {
                            arr[i][j] = min(matrix[i][j] + arr[i - 1][j],
                                            matrix[i][j] + arr[i - 1][j + 1]);
                        } else if(j+1 == n){
                            arr[i][j] = min(matrix[i][j] + arr[i - 1][j],
                                             matrix[i][j] + arr[i - 1][j - 1]);
                        } else {
                            arr[i][j] = min({matrix[i][j] + arr[i - 1][j],
                                             matrix[i][j] + arr[i - 1][j + 1],
                                             matrix[i][j] + arr[i - 1][j - 1]});
                        }
                    }
                }
                int ans = INT_MAX;
                //starting from top, thus minimum at bottom
                for (int i = m - 1; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (ans > arr[i][j]) {
                            ans = arr[i][j];
                        }
                    }
                }
                return ans;
            }
        };
