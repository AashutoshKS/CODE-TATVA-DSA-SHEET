//PROBLEM :
      Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
      
      A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
      
      Return the maximum length of a subarray with positive product.


//APPROACH : 
      Hint 1
          Split the whole array into subarrays by zeroes since a subarray with positive product cannot contain any zero.
      Hint 2
          If the subarray has even number of negative numbers, the whole subarray has positive product.
      Hint 3
          Otherwise, we have two choices, either - remove the prefix till the first negative element in this subarray, or remove the suffix starting from the 
            last negative element in this subarray.


        
//CODE :
      class Solution {
      public:
          int getMaxLen(vector<int>& nums) {
              int ans = 0, last_zero = -1, first_neg = -1, neg = 0;         
      
              for (int i = 0; i < nums.size(); i++) {
                  if (nums[i] == 0) {
                      neg = 0;
                      first_neg = -1;
                      last_zero = i;
                  } else {
                      if (nums[i] < 0) {
                          neg++;
                          if (first_neg == -1) first_neg = i;
                      }
      
                      if (neg % 2 == 0) {
                          ans = max(ans, i - last_zero);
                      } else {
                          ans = max(ans, i - first_neg);
                      }
                  }
              }
              return ans;
          }
      };
