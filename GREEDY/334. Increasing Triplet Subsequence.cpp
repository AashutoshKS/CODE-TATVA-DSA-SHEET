//PROBLEM :

      Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
        If no such indices exists, return false.


//APPROACH :
      take 2 variable for 2 numbers
      and observe the relation if the 3rd element of the sequence is nums[i]



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          bool increasingTriplet(vector<int>& nums) {
              int first = INT_MAX;
              int second = INT_MAX;
      
              for (int i=0;i<nums.size();i++){
                  if (nums[i] <= first){
                      first = nums[i];
                  }
                  else if (nums[i] <= second){ 
                      second = nums[i];  
                  }
                  else{
                      return true; 
                  }
              }
              return false;
          }
      };
