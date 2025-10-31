//PROBLEM :

      Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a 
      beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
      
      perm[i] is divisible by i.
      i is divisible by perm[i].
      Given an integer n, return the number of the beautiful arrangements that you can construct.



//APPROACH :
      we have to keep track of 2 things, which elements we have used and which elements we can use
      take a list of size n to track the elements which you have used


      for each index check if you can use any specific element or not based on both condition and availability.
      use backtrack to check all possibilities.


//CODE :
      class Solution {
      public:
          int ans = 0;
          void solve(int n, vector<int>& used, vector<int>curr) {
              if(curr.size() == n) {
                  ans++;
                  return ;
              }
              int idx = curr.size();
              for(int i = 0;i < n; i++) {
                  if(used[i] == 0 && ((i+1)%(idx+1) == 0 || (idx+1)%(i+1) == 0)) {
                      used[i] = 1;
                      curr.push_back(i+1);
                      solve(n, used, curr);
                      used[i] = 0;
                      curr.pop_back();
                  }
              }
      
          }
          int countArrangement(int n) {
              vector<int>used(n, 0);
              vector<int>curr;
              solve(n, used, curr);
              return ans;
          }
      };
