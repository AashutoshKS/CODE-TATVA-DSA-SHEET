//PROBLEM :

        Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
        
        Return the kth positive integer that is missing from this array.


//APPROACH :
        Use the range of 5 to find the missing number 
        if(nums[i] > 5) that means k can not be from 1-5, thus increment k
        do while you find that index


//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(1)



//CODE :
          class Solution {
          public:
              int findKthPositive(vector<int>& nums, int k) {
                  for(int i = 0;i<nums.size();i++) {
                      if(k >= nums[i]) k++;
                      else return k;
                  }
                  return k;
              }
          };
