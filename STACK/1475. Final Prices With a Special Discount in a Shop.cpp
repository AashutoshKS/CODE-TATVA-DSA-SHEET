//PROBLEM :

      You are given an integer array prices where prices[i] is the price of the ith item in a shop.
      
      There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum 
      index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
      
      Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.



//APPROACH :
      find the next smaller in each case and retuce the value of nums[i]



//CODE :
      class Solution {
      public:
          vector<int> finalPrices(vector<int>& prices) {
              for(int i = 0; i < prices.size();i++) {
                  for(int j = i + 1; j < prices.size();j++) {
                      if(prices[j] <= prices[i]) {
                          prices[i] -= prices[j];
                          break;
                      }
                  }
              }
              return prices;
          }
      };



//CODE :
using STACK:


      class Solution {
      public:
          vector<int> finalPrices(vector<int>& prices) {
              stack<int>st;
              for(int i = prices.size() - 1; i >= 0;i--) {
                  if(st.empty()) {
                      st.push(prices[i]);
                  } else {
                      while(!st.empty() && st.top() > prices[i]) st.pop();
                      int val = prices[i];
                      if(!st.empty() && st.top() <= prices[i]) prices[i] -= st.top();
                      st.push(val);
                  }
              }
              return prices;
          }
      };
