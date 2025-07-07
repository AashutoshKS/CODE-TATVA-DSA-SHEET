//PROBLEM : 

      The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
      
      The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
      
      Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
      
      To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
      
      Return the knight's minimum initial health so that he can rescue the princess.
      
      Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.



//APPROACH :
      you can think of binary search here
      where the low is 1
      and high = 10^5, since minimum value a node can have is -1000 and for a path u need m + n box ie(200 + 200) for maximum
      which is 400*1000 = 4*10^5
        use binary search from 1 -> 10^5



//CODE :
      class Solution {
      public:
          bool solve(int mid, vector<vector<int>>nums) {
              for (int i = 0; i < nums.size(); i++) {
                  for (int j = 0; j < nums[0].size(); j++) {
                      if(i == 0 && j == 0) nums[i][j] += mid;
                      else if(i == 0)  nums[i][j] += nums[i][j-1];
                      else if(j == 0) nums[i][j] += nums[i-1][j];
                      else nums[i][j] += max(nums[i][j-1], nums[i-1][j]);
                      if(nums[i][j] <= 0) nums[i][j] = -1e4;
                  }
              }
              return nums.back().back() > 0;
          }
      
          int calculateMinimumHP(vector<vector<int>>& dungeon) {
              int m = dungeon.size(), n = dungeon[0].size();
              int low = 1, high = 1e5, ans = INT_MAX;
              while(low <= high) {
                  int mid = (low+high)/2;
                  if(solve(mid, dungeon)) {
                      ans = min(ans,mid);
                      high = mid - 1;
                  } else {
                      low = mid + 1;
                  }
              }
              return ans;
          }
      };
      
        
            
//DP :
      class Solution {
      public:
          int calculateMinimumHP(vector<vector<int>>& dungeon) {
              int m = dungeon.size(), n = dungeon[0].size();
              vector<vector<int>>nums(m+1,vector<int>(n+1));
              for(int i = m - 1; i >= 0;i--) {
                  for(int j = n - 1;j >= 0; j--) {
                      if(i == m-1 && j == n- 1) {
                          if(dungeon[i][j] > 0)  nums[i][j] = 1;
                          else nums[i][j] = 1 - dungeon[i][j];
                      } else {
                          int r = (j+1) >= n ? INT_MAX : nums[i][j+1];
                          int d = (i+1) >= m ? INT_MAX : nums[i+1][j];
                          nums[i][j] = min(r,d) - dungeon[i][j];
                          nums[i][j] > 0 ? nums[i][j] = nums[i][j] : nums[i][j] = 1;
                      }
                  }
              }
              return nums[0][0];
          }
      };
