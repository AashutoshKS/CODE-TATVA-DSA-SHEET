//PROBLEM :

    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
    
    The distance between two cells sharing a common edge is 1.



//APPROACH :
    For each idx where nums[i][j] == 1 use dfs, or bfs to deduce the closest 0;


//CODE :
      class Solution {
      public:
          vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
              int n = mat.size();
              int m = mat[0].size();
              vector<vector<int>>vis(n,vector<int>(m,0));
              vector<vector<int>>ans(n,vector<int>(m,0));
              queue<pair<pair<int,int>,int>>q;
              for(int i = 0;i < n; i++) {
                  for(int j = 0;j < m;j++) {
                      if(mat[i][j] == 0) {
                          q.push({{i,j},0});
                          vis[i][j] = 1;
                      }
                  }
              }
              vector<int>rows = {-1,0,1,0};
              vector<int>cols = {0,1,0,-1};
              while(!q.empty()) {
                  int r = q.front().first.first;
                  int c = q.front().first.second;
                  int step = q.front().second;
                  q.pop();
                  ans[r][c] = step;
                  for(int i = 0;i < 4;i++) {
                      int curr_r = r + rows[i];
                      int curr_c = c + cols[i];
                      if(curr_r >= 0 && curr_r < n && curr_c >= 0 && curr_c < m && vis[curr_r][curr_c] == 0) {
                          vis[curr_r][curr_c] = 1;
                          q.push({{curr_r,curr_c},step + 1});
                      }
                  }
              }
              return ans;
          }
      };
