//PROBLEM :
      You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
      
      On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
        However, you can buy it then immediately sell it on the same day.
      
      Find and return the maximum profit you can achieve.


//APPROACH :
      Since you can buy and sell multiple stock....
      whenever you find price lower than prev, sell the product at that day.....
      same as Best Time to Buy and Sell Stock I



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          int maxProfit(vector<int>& nums) {
              int minPrice=nums[0];
              int maxProfit=0;
              for(int i=0;i<nums.size();i++){
                  if(nums[i] >= minPrice){
                      maxProfit+=(nums[i]-minPrice);
                  }
                  minPrice=nums[i];
              }
              return maxProfit;
          }
      };
