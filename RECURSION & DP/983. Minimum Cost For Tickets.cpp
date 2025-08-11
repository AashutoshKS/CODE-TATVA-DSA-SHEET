//PROBLEM :

      You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an 
        integer from 1 to 365.
      
      Train tickets are sold in three different ways:
      
      a 1-day pass is sold for costs[0] dollars,
      a 7-day pass is sold for costs[1] dollars, and
      a 30-day pass is sold for costs[2] dollars.
      The passes allow that many days of consecutive travel.
      
      For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
      Return the minimum number of dollars you need to travel every day in the given list of days.




//CODE :
      class Solution {
      public:
          int mincostTickets(vector<int>& days, vector<int>& costs) {
              vector<int>nums(days.back() + 1 , 0);
              for (int i = 0; i < days.size(); i++) {
                  nums[days[i]]++;
              }
              vector<int>dp(days.back() + 1);
              dp[0] = 0;
              for (int i = 1; i < dp.size(); i++) {
                  if (nums[i] == 0) {
                      dp[i] = dp[i - 1];
                      continue;
                  }
      
                  int pass1 = costs[0] + dp[max(i - 1, 0)];
                  int pass7 = costs[1] + dp[max(i - 7, 0)];
                  int pass30 = costs[2] + dp[max(i - 30, 0)];
      
                  dp[i] = min(pass1, min(pass7, pass30));
              }
              return dp.back();
          }
      };
