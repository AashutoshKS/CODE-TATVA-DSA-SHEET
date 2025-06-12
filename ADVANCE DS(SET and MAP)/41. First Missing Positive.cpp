//PROBLEM :

      Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
      
      You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



//APPROACH :
      1 -> check if 1 is present or not if yes continue, else return 1;
      2 -> number < 0 and number > size are irrelevent
        Since, need +ve number , id a number n+1 is present that means there is at least 1 number from 1 - n that is missing
        thus convert all such numbers ie < 0 and > n to 1
      3 -> convert att the numbers to -ve 
      4 -> traverse the list and return the index of the 1st number which is positive;


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


//CODE :        
      class Solution {
      public:
          int firstMissingPositive(vector<int>& nums) {
              int isone = 0;
              int n = nums.size();
              for (int i = 0; i < nums.size(); i++) {
                  if (nums[i] == 1) {
                      isone++;
                      break;
                  }
              }
              if (isone == 0)
                  return 1;
              for (int i = 0; i < nums.size(); i++) {
                  if (nums[i] <= 0 || nums[i] > nums.size())
                      nums[i] = 1;
              }
              for (int i = 0; i < nums.size(); i++) {
                  int val = abs(nums[i]);
                  nums[val - 1] = -abs(nums[val - 1]);
              }
              for (int i = 0; i < nums.size(); i++) {
                  if (nums[i] > 0)
                      return i + 1;
              }
              return n + 1;
          }
      };
