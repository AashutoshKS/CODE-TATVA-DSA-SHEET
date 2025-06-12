//PROBLEM :

      Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


//APPROACH 1:
    Use map to check the number which is not present from range 1 - n

//APPROACH 2 :
      since element 0 - n are present instead of 1 number
      this the total sum of the given arr will be
      
      sum(0 - n) - the missing number
      using sum formula to compute the total sum
      and reduce the current sum of the list


//COMPLEXITY :
      TIME COMLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          int missingNumber(vector<int>& nums) {
              int sum=0,n=nums.size();
              int ans =(n*(n+1))/2;
              for(int i=0;i<n;i++){
                  sum+=nums[i];
              }
              return ans-sum;
          }
      };
