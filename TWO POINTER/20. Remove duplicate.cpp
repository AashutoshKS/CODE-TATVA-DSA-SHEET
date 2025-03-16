//PROBLEM :
          Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. 
          Then return the number of unique elements in nums.
          
          Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
          
          Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
          The remaining elements of nums are not important as well as the size of nums.
          Return k.

//APPROACH :
          since we have to solve it without using extra space and have to return the size of resultant list we will use a pointe to keep track of new list 


//COMPLEXITY :
          TIME COMPLEXITY : O(n);
          SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              int removeDuplicates(vector<int>& nums) {
                  int j=1;
                  for(int i=1;i<nums.size();i++){
                      if(nums[i]!=nums[i-1]){
                          nums[j]=nums[i];
                          j++;
                      }
                  }
              return j;
              }
          };
