//PEOBLEM :

      Given an integer array nums, find a subarray that has the largest product, and return the product.
      
      The test cases are generated so that the answer will fit in a 32-bit integer.


//APPROACH : BRUTE
      check all the subarray and deduce the maximum produxt

//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : : O(1)



//APPROACH : Kadanes algo
        key points to note
        if we multiply a number nd product is -ve, it can be +ve in future
        but if the product it 0, no matter what value you multipy it will stay 0
              thus whenever the product is 0 reinitialise it back to 1
        
        do the same from the other end too

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : : O(n)



//CODE :
      class Solution {
      public:
          int maxProduct(vector<int>& nums) {
              int maxProduct = INT_MIN;
              for (int i = 0, product = 1 ; i < nums.size(); i++) {
                  product *= nums[i];
                  maxProduct = max(maxProduct, product);
                  if (product == 0) {
                      product = 1;
                  }
              }
              for (int i = nums.size() - 1, product = 1; i >= 0; i--) {
                  product *= nums[i];
                  maxProduct = max(maxProduct, product);
                  if (product == 0) {
                      product = 1;
                  }
              }
      
              return maxProduct;
          }
      };
