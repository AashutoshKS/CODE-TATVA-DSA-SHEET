//PROBLEM :

      An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
      
      For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
      Given an integer array nums, return the number of arithmetic subarrays of nums.
      
      A subarray is a contiguous subsequence of the array.



//APPROACH :
      since we require subarray compute the difference between 2 consecutive element, 
        move the 2nd pointer till you find same difference between 2 elements, increment ans each time
      
      it is slight modification of brute force n^3 solution
      



//CODE :
      class Solution {
      public:
          int numberOfArithmeticSlices(vector<int>& nums) {
              if (nums.size() < 3)
                  return 0;
              int count = 0;
              for(int i = 0; i < nums.size() - 2; i++) {
                  int diff = nums[i+1] - nums[i];
                  for(int j = i + 2; j < nums.size(); j++) {
                      if((nums[j] - nums[j-1]) != diff) break;
                      if((j - i + 1) >= 3) count++;
                  }
              }
              return count;
          }
      };
