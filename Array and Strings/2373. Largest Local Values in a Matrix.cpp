//PROBLEM : 
      You are given an n x n integer matrix grid.

      Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
      
      maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
      In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
      
      Return the generated matrix.

//APPROACH : 
        we know the size of ans grid is n-2*n-2 
        find the maximum for each 3*3 grid and find the resultant


//COMPLEXITY  :
        TIME COMPLEXITY : O(n*n)
        SPACE COMPLEXITY : O((n-2)*(n-2)) = O(n*n)


//CODE
class Solution {
public:
    int find(vector<vector<int>>& grid,int i,int j) {
        int great = INT_MIN;
        for(int k = i;k < i + 3;k++) {
            for(int k1 = j;k1 < j+ 3;k1++) {
                great = max(great,grid[k][k1]);
            }
        }
        return great;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        for(int i = 0;i < grid.size() - 2;i++) {
            vector<int>nums;
            for(int j = 0 ;j< grid.size() - 2;j++) {
                int big = find(grid,i,j);
                nums.push_back(big);
            }
            ans.push_back(nums);
            nums.clear();
        }
        return ans;
    }
};
