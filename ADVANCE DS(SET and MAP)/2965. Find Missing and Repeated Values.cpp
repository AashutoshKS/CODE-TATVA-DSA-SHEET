//PROBLEM :

      You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
      Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
      
      Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
      


//APPROACH :
      convert it to linear list and sort the list 
      traverse through to find the missing and repeated number



//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(n*n)



//CODE :
      class Solution {
      public:
          vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
              vector<int>v;
              int first,second;
              for(int i=0;i<grid.size();i++){
                  for(int j=0;j<grid.size();j++){
                      v.push_back(grid[i][j]);
                  }
              }
              sort(v.begin(),v.end());
              int sum=v[0];
              for(int i1=1;i1<v.size();i1++){
                  if(v[i1]==v[i1-1])
                  first=v[i1];
                  sum+=v[i1];
              }
              sum=sum-first;
              int n=grid.size();
              int sumans=((n*n)*(n*n+1))/2;
              second=sumans-sum;
              return {first,second};
          }
      };
