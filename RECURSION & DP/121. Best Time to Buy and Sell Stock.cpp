//PROBLEM : 

    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



//APPROACH :
    Only 1 transaction is possible
    at a spefic index i the max profit is maximum from 0 -> i  - minimum from 0 -> i
        for each index compute the maximum and minimum and modify the answer



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          int maxProfit(vector<int>& prices) {
              int  mini = prices[0];
              int ans = 0;
              for (int i = 1; i < prices.size(); i++) {
                  mini = min(mini,prices[i]);
                  ans = max(ans, prices[i] - mini);
              }
              return ans;
          }
      };
