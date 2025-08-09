//PROBLEM : 

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    
    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    
    You may assume that you have an infinite number of each kind of coin.



//APPROACH : RECURSION
      use pick no pick, 
        in case you pick the coin increase the count of coins and stay at the current index and choose it again if possible
        else move the index


//APPROACH : DP 
      For each amount from 1 -> amount check what is the minimum number f required coins


//CODE :
      class Solution {
      public:
          int coinChange(vector<int>& coins, int amount) {
              int n = coins.size();
              int arr[n + 1][amount + 1];
              for (int i = 0; i < n + 1; i++) {
                  for (int j = 0; j < amount + 1; j++) {
                      if (i == 0) {
                          arr[i][j] = amount + 1;
                      } else if (j == 0) {
                          arr[i][j] = 0;
                      } else if (coins[i-1] > j){
                          arr[i][j]=arr[i-1][j];
                      } else {
                          int k=j-coins[i-1];
                          arr[i][j]=min(arr[i-1][j],arr[i][k] + 1);
                      }
                  }
              }
              return arr[n][amount] > amount ? -1 : arr[n][amount];
          }
      };
