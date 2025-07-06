//PROBLEM :

      You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
      
      Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
      
      You may assume that you have an infinite number of each kind of coin.
      
      The answer is guaranteed to fit into a signed 32-bit integer.



//APPROACH :
      we have 2 choice 
          pick a coin and dont move forward if amount is not found
          skip the coin and move to next



//CODE : RECURSION
      class Solution {
      public:
          int ans = 0;
          void solve(vector<int>& coins, int amount, int idx) {
              if (amount == 0) {
                  ans++;
                  return;
              }
              if (amount < 0 || idx == coins.size()) return;
              solve(coins, amount - coins[idx], idx);
              solve(coins, amount, idx + 1);
          }
          int change(int amount, vector<int>& coins) {
              sort(coins.begin(), coins.end());
              solve(coins, amount, 0);
              return ans;
          }
      };




//CODE : DP
      class Solution {
      public:
          int change(int amount, vector<int>& coins) {
              vector<unsigned long long> dp(amount + 1);
              dp[0] = 1;
      
              for (int i = 0; i < coins.size(); i++)
                  for (int j = coins[i]; j <= amount; ++j)
                      dp[j] += dp[j - coins[i]];
      
              return dp[amount];
          }
      };
