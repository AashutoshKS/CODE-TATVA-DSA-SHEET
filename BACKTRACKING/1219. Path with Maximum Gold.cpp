//PROBLEM :

      In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell,
        0 if it is empty.
      
      Return the maximum amount of gold you can collect under the conditions:
      
      Every time you are located in a cell you will collect all the gold in that cell.
      From your position, you can walk one step to the left, right, up, or down.
      You can't visit the same cell more than once.
      Never visit a cell with 0 gold.
      You can start and stop collecting gold from any position in the grid that has some gold.



//APPROACH : 
      Its simple DFS just traverse for each index where grid[i][j] != 0
      Uppdate the visited array since you can not go to the place which you have already visited
      Maintain the current sum and maximum ans....



//CODE :
      class Solution {
      public:
          int n, m;
          void solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int curr, int& ans, int i,int j) {
              if(i == n || j == m || i < 0 || j < 0 || vis[i][j] == 1 || grid[i][j] == 0) {
                  ans = max(ans, curr);
                  return;
              }
              vis[i][j] = 1;
              solve(grid, vis, curr + grid[i][j], ans, i + 1, j);
              solve(grid, vis, curr + grid[i][j], ans, i - 1, j);
              solve(grid, vis, curr + grid[i][j], ans, i, j + 1);
              solve(grid, vis, curr + grid[i][j], ans, i, j - 1);
              vis[i][j] = 0;
          }
          int getMaximumGold(vector<vector<int>>& grid) {
              n = grid.size(), m = grid[0].size();
              vector<vector<int>> vis(n, vector<int>(m));
              int ans = 0;
              for(int i = 0; i < n; i++) {
                  for(int j = 0; j < m; j++) {
                      if(grid[i][j] != 0) {
                          solve(grid, vis, 0, ans, i, j);
                      }
                  }
              }
              return ans;
          }
      };
