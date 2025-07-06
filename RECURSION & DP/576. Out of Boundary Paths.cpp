//PROBLEM :

      There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four 
      adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
      
      Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
      Since the answer can be very large, return it modulo 109 + 7.


//APPROACH 1: 
        use BFS, to find all the possible moves unless we reach to out of bound


//CODE:
      class Solution {
      public:
          int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
              queue<pair<pair<int,int>,int>>q;
              if(maxMove == 0) return 0;
              q.push({{startRow, startColumn}, maxMove});
              vector<int>rows = {-1,0,1,0};
              vector<int>cols = {0,1,0,-1};
              long long ans = 0,MOD =1e9 + 7;
              while(!q.empty()) {
                  int r = q.front().first.first;
                  int c = q.front().first.second;
                  int move = q.front().second;
                  q.pop();
                  for(int i = 0;i < 4; i++) {
                      int curr_r = r + rows[i];
                      int curr_c = c + cols[i];
                      if(curr_r >= 0 && curr_r < n && curr_c >= 0 && curr_c < m) {
                          if(move > 1) q.push({{curr_r,curr_c},move - 1});
                      } else ans = (ans + 1)%MOD;
                  }
              }
              return ans;
          }
      };



//APPROACh :
            Such an approach takes a lot space thus we must use DP



//CODE :
      class Solution {
      public:
          const int MOD = 1e9 + 7;
          int dp[51][51][51];  
      
          int dfs(int n, int m, int maxMove, int i, int j) {
              if (i < 0 || j < 0 || i >= n || j >= m) return 1;
              if (maxMove == 0) return 0;
      
              if (dp[maxMove][i][j] != -1) return dp[maxMove][i][j];
      
              int totalPaths = 0;
              vector<int> dx = {-1, 0, 1, 0};
              vector<int> dy = {0, 1, 0, -1};
              for (int d = 0; d < 4; d++) {
                  totalPaths = (totalPaths + dfs(n, m, maxMove - 1, i + dx[d], j + dy[d])) % MOD;
              }
      
              return dp[maxMove][i][j] = totalPaths;
          }
      
          int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
              memset(dp, -1, sizeof(dp));
              return dfs(m, n, maxMove, startRow, startColumn);
          }
      };
