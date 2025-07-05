//PROBLEM :

      Given a triangle array, return the minimum path sum from top to bottom.
      
      For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, 
        you may move to either index i or index i + 1 on the next row.



//APPROACH :
        same as minimum falling path, 
        you just have to handle the increasing number of elements in each cols


//CODE :
      class Solution {
      public:
          int minimumTotal(vector<vector<int>>& tri) {
              int k = tri.size() - 1;
              for(int i = 1 ;i < tri.size(); i++) {
                  int n = tri[i].size();
                  for(int j = 0;j < tri[i].size();j++){
                      if(j == 0){
                          tri[i][j] += tri[i-1][0]; 
                      } else if(j == n-1) {
                          tri[i][j] += tri[i-1][n - 2]; 
                      } else {
                          tri[i][j] = min(tri[i-1][j-1],tri[i-1][j]) + tri[i][j];
                      }
                  }
              }
              int ans = INT_MAX;
              for(int i = 0;i < tri[k].size();i++) {
                  ans = min(ans,tri[k][i]);
              }
              return ans;
          }
      };
