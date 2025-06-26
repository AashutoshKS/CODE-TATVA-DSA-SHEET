//PROBLEM :

      In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. 
        (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
      
      We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
      
      Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
      
      If it cannot be done, return -1.



//APPROACH :
      Greedily check both the cases iie.
        -> can you make the 1st row equal?
        -> can you make 2nd row equal?



//COMPLEXITY :
      TIME COMPLEXITY : O(2*6*n) = O(n)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
              int ans = INT_MAX;
              for(int i = 1;i <= 6; i++ ){
                  int count = 0, k = 0;
                  for(int j = 0;j < tops.size(); j++) {
                      if(tops[j] == i) continue;
                      else if(bottoms[j] == i) count++;
                      else {
                          k = 1;
                          break;
                      }
                  }
                  if(k == 0) ans = min(ans,count);
              }
              for(int i = 1;i <= 6; i++ ){
                  int count = 0, k = 0;
                  for(int j = 0;j < tops.size(); j++) {
                      if(bottoms[j] == i) continue;
                      else if(tops[j] == i) count++;
                      else {
                          k = 1;
                          break;
                      }
                  }
                  if(k == 0) ans = min(ans,count);
              }
              if(ans == INT_MAX) return - 1;
              return ans;
          }
      };
