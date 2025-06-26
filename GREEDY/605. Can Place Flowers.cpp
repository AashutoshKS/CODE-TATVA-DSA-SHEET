//PROBLEM :

      You have a long flowerbed in which some of the plots are planted, and some are not. 
          However, flowers cannot be planted in adjacent plots.
      
      Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
      and an integer n, return true if n new flowers can be planted in the flowerbed without violating the 
      no-adjacent-flowers rule and false otherwise.



//APPROACH :
        use greedy to place the plant when ever you get a valid slot


//CODE :

      class Solution {
      public:
          bool canPlaceFlowers(vector<int>& flowerbed, int n) {
              int count = 0, beg, end;
              for (int i = 0; i < flowerbed.size(); i++) {
                  if (flowerbed[i] == 1) {
                      beg = i;
                      break;
                  } else if (i == flowerbed.size() - 1) {
                      return (n - (count + 2) / 2) <= 0;
                  } else
                      count++;
              }
              n = n - (count) / 2;
              count = 0;
              for (int j = flowerbed.size() - 1; j >= 0; j--) {
                  if (flowerbed[j] == 1) {
                      end = j;
                      break;
                  } else
                      count++;
              }
              n = n - (count) / 2;
              if (n <= 0)
                  return true;
              count = 0;
              for (int i = beg; i <= end; i++) {
                  if (flowerbed[i] == 1) {
                      n -= (count - 1) / 2;
                      count = 0;
                  } else
                      count++;
              }
              return n <= 0;
          }
      };
             
