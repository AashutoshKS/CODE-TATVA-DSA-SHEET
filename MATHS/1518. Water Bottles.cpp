//PROBLEM :

      There are numBottles water bottles that are initially full of water. 
      You can exchange numExchange empty water bottles from the market with one full water bottle.
      
      The operation of drinking a full water bottle turns it into an empty bottle.
      
      Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.



//APPROACH : 
      Count the number of empty bottle you have
      include it if count > change else return



//CODE :

Java Script

      var numWaterBottles = function(numBottles, numExchange) {
          let ans = numBottles;
          while (numBottles >= numExchange) {
              ans += Math.floor(numBottles / numExchange);
              numBottles = Math.floor(numBottles / numExchange) + numBottles % numExchange;
          }
          return ans;    
      };

----------------------------------------------------------------------------------------------------------
C++
  
      class Solution {
      public:
          int numWaterBottles(int numBottles, int numExchange) {
              int ans = numBottles;
              while (numBottles >= numExchange) {
                  ans += numBottles / numExchange;
                  numBottles = numBottles / numExchange + numBottles % numExchange;
              }
              return ans;
          }
      };
