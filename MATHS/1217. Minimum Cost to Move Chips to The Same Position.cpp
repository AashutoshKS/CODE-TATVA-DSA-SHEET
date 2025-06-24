//PROBLEM :

      We have n chips, where the position of the ith chip is position[i].
      
      We need to move all the chips to the same position. In one step, we can change the position of the ith chip 
      from position[i] to:
      
      position[i] + 2 or position[i] - 2 with cost = 0.
      position[i] + 1 or position[i] - 1 with cost = 1.
      Return the minimum cost needed to move all the chips to the same position.


//APPROACH :
      we just have to check the odd and even numebers
      consider n even and m odd number 
      all odd can be placed at one position by 0 cost, similarly even can be place to even postion with 0 cost
      return min of odd or even


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)

        
//CODE :
      class Solution {
      public:
          int minCostToMoveChips(vector<int>& position) {
              int cnt[2] = {};
              for (auto p : position)
                  ++cnt[p % 2];
              return min(cnt[0], cnt[1]);
          }
      };
             
