//PROBLEM :

      There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:
      
      multiply the number on display by 2, or
      subtract 1 from the number on display.
      Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.


//APPRROACH :
      While target is larger than startValue, add 1 if it is odd, else divide by 2. 
      we need to do startValue - target additions to reach startValue 
        since we have to perform startValue - target add operations



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY O(1)



//CODE :
      class Solution {
      public:
          int brokenCalc(int startValue, int target) {
              int ans = 0;
              while(target > startValue) {
                  if(target%2 == 0) target /= 2;
                  else target++;
                  ans++;
              }
              return ans + startValue - target;
          }
      };
