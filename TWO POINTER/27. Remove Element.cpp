//PROBLEM :

                      Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
                      Then return the number of elements in nums which are not equal to val.
                      
                      Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
                      
                      Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums 
                      are not important as well as the size of nums.
                      Return k.


//APPROACH :
                      have 2 pointer 
                          -> one to traverse the list
                          -> sec to keep track of the elements which are not equal to val
                      the sec pointer will also be used to place all the values which are not equal to value at the beginning 


//CODE :
                  class Solution {
                  public:
                      int removeElement(vector<int>& nums, int val) {
                          int i=0;
                          for(int j=0;j<nums.size();){
                              if(nums[j]!=val){
                                  nums[i]=nums[j];
                                  i++;
                                  j++;
                              }
                              else{
                                  j++;
                              }
                          }
                          return i;
                      }
                  };
